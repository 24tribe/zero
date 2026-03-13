// taken from https://github.com/Kaotic/ImGuiAndroidVulkanHook/blob/main/Menu/Menu.cpp

#include <functional>
#include <cstdio>
#include <vector>

#include <MinHook.h>

#include <volk.h>

#include <imgui.h>
#include <backends/imgui_impl_vulkan.h>
#include <backends/imgui_impl_win32.h>

std::function<void()> gCallback;

static VkInstance g_Instance = VK_NULL_HANDLE;
static VkPhysicalDevice g_PhysicalDevice = VK_NULL_HANDLE;
static VkDevice g_Device = VK_NULL_HANDLE;
static VkQueue g_Queue = VK_NULL_HANDLE;
static VkCommandPool g_CommandPool = VK_NULL_HANDLE;
static HWND g_NativeWindow = NULL;
static VkSwapchainKHR g_Swapchain = VK_NULL_HANDLE;
static VkExtent2D g_SwapchainExtent = {0, 0};
static VkSurfaceKHR g_Surface = VK_NULL_HANDLE;
static std::vector<VkImage> g_SwapChainImages;
static VkDescriptorPool g_DescriptorPool = VK_NULL_HANDLE;
static std::vector<VkFramebuffer> g_Framebuffers;
static std::vector<VkImageView> g_SwapChainImageViews;
static VkRenderPass g_RenderPass = VK_NULL_HANDLE;

static bool g_ImGuiInitialized = false;
static bool g_InitInProgress = false;
static bool g_InSubmit = false;

struct RenderContext {
    VkCommandBuffer commandBuffer;
    VkFence fence;
    bool inUse;
    
    RenderContext() : commandBuffer(VK_NULL_HANDLE), fence(VK_NULL_HANDLE), inUse(false) {}
};

static RenderContext g_RenderContexts[2];
static uint32_t g_CurrentContext = 0;

static int CreateAndEnableHook(
    void *func, void *funcDetour, void **trampoline
) {
    if (MH_CreateHook(func, funcDetour, trampoline) != MH_OK) {
        printf("Failed to create hook\n");
        return -1;
    }

	if (MH_EnableHook(func, TRUE) != MH_OK) {
        printf("Failed to enable hook\n");
        return -1;
    }

    return 0;
}

static uint32_t findGraphicsQueueFamily() {
    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(g_PhysicalDevice, &queueFamilyCount, nullptr);
    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(g_PhysicalDevice, &queueFamilyCount, queueFamilies.data());

    for (uint32_t i = 0; i < queueFamilyCount; i++) {
        if (queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            return i;
        }
    }
    return UINT32_MAX;
}

static VkCommandPool createCommandPool() {
    VkCommandPoolCreateInfo poolInfo{};
    poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    poolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    poolInfo.queueFamilyIndex = findGraphicsQueueFamily();

    VkCommandPool commandPool = VK_NULL_HANDLE;
    VkResult result = vkCreateCommandPool(g_Device, &poolInfo, nullptr, &commandPool);
    if (result == VK_SUCCESS) {
        printf("Command pool created successfully\n");
    } else {
        printf("Failed to create command pool: %d\n", result);
    }
    return commandPool;
}

static bool createDescriptorPool() {
    VkDescriptorPoolSize pool_sizes[] = {
        { VK_DESCRIPTOR_TYPE_SAMPLER, 1000 },
        { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1000 },
        { VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, 1000 },
        { VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, 1000 },
        { VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, 1000 },
        { VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, 1000 },
        { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1000 },
        { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 1000 },
        { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, 1000 },
        { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, 1000 },
        { VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, 1000 }
    };

    VkDescriptorPoolCreateInfo pool_info = {};
    pool_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    pool_info.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
    pool_info.maxSets = 1000;
    pool_info.poolSizeCount = std::size(pool_sizes);
    pool_info.pPoolSizes = pool_sizes;

    if (vkCreateDescriptorPool(g_Device, &pool_info, nullptr, &g_DescriptorPool) != VK_SUCCESS) {
        printf("Failed to create descriptor pool\n");
        return false;
    }

    return true;
}

static VkRenderPass createImGuiRenderPass() {
    VkAttachmentDescription attachment = {};
    attachment.format = VK_FORMAT_B8G8R8A8_UNORM;
    attachment.samples = VK_SAMPLE_COUNT_1_BIT;
    attachment.loadOp = VK_ATTACHMENT_LOAD_OP_LOAD; // Important: LOAD to preserve Unity rendering
    attachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    attachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachment.initialLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
    attachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    VkAttachmentReference color_attachment = {};
    color_attachment.attachment = 0;
    color_attachment.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass = {};
    subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments = &color_attachment;

    VkSubpassDependency dependency = {};
    dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
    dependency.dstSubpass = 0;
    dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT;
    dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

    VkRenderPassCreateInfo info = {};
    info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    info.attachmentCount = 1;
    info.pAttachments = &attachment;
    info.subpassCount = 1;
    info.pSubpasses = &subpass;
    info.dependencyCount = 1;
    info.pDependencies = &dependency;

    VkRenderPass renderPass;
    VkResult result = vkCreateRenderPass(g_Device, &info, nullptr, &renderPass);
    if (result != VK_SUCCESS) {
        printf("Failed to create render pass: %d\n", result);
        return VK_NULL_HANDLE;
    }

    return renderPass;
}

static void createImGuiFramebuffers() {
    g_Framebuffers.resize(g_SwapChainImages.size());
    g_SwapChainImageViews.resize(g_SwapChainImages.size());

    for (size_t i = 0; i < g_SwapChainImages.size(); i++) {
        VkImageViewCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        createInfo.image = g_SwapChainImages[i];
        createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        createInfo.format = VK_FORMAT_B8G8R8A8_UNORM;
        createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        createInfo.subresourceRange.baseMipLevel = 0;
        createInfo.subresourceRange.levelCount = 1;
        createInfo.subresourceRange.baseArrayLayer = 0;
        createInfo.subresourceRange.layerCount = 1;

        if (vkCreateImageView(g_Device, &createInfo, nullptr, &g_SwapChainImageViews[i]) != VK_SUCCESS) {
            printf("Failed to create image view %zu\n", i);
            continue;
        }

        VkImageView attachments[] = { g_SwapChainImageViews[i] };
        VkFramebufferCreateInfo framebufferInfo = {};
        framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebufferInfo.renderPass = g_RenderPass;
        framebufferInfo.attachmentCount = 1;
        framebufferInfo.pAttachments = attachments;
        framebufferInfo.width = g_SwapchainExtent.width;
        framebufferInfo.height = g_SwapchainExtent.height;
        framebufferInfo.layers = 1;

        if (vkCreateFramebuffer(g_Device, &framebufferInfo, nullptr, &g_Framebuffers[i]) != VK_SUCCESS) {
            printf("Failed to create framebuffer %zu\n", i);
        }
    }
}

static VkCommandBuffer createCommandBuffer() {
    if (g_Device == VK_NULL_HANDLE || g_CommandPool == VK_NULL_HANDLE) {
        printf("Device or CommandPool is null\n");
        return VK_NULL_HANDLE;
    }

    VkCommandBufferAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandPool = g_CommandPool;
    allocInfo.commandBufferCount = 1;

    VkCommandBuffer commandBuffer;
    VkResult result = vkAllocateCommandBuffers(g_Device, &allocInfo, &commandBuffer);
    if (result == VK_SUCCESS) {
        printf("Command buffer created successfully\n");
    } else {
        printf("Failed to create command buffer: %d\n", result);
        return VK_NULL_HANDLE;
    }
    return commandBuffer;
}

static bool uploadFonts() {
    VkCommandBuffer commandBuffer = createCommandBuffer();
    if (commandBuffer == VK_NULL_HANDLE) return false;

    VkCommandBufferBeginInfo beginInfo = {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

    if (vkBeginCommandBuffer(commandBuffer, &beginInfo) != VK_SUCCESS) {
        vkFreeCommandBuffers(g_Device, g_CommandPool, 1, &commandBuffer);
        return false;
    }

    ImGui_ImplVulkan_CreateFontsTexture();

    if (vkEndCommandBuffer(commandBuffer) != VK_SUCCESS) {
        vkFreeCommandBuffers(g_Device, g_CommandPool, 1, &commandBuffer);
        return false;
    }

    VkSubmitInfo submitInfo = {};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &commandBuffer;

    VkFence fence;
    VkFenceCreateInfo fenceInfo = {};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    
    if (vkCreateFence(g_Device, &fenceInfo, nullptr, &fence) != VK_SUCCESS) {
        vkFreeCommandBuffers(g_Device, g_CommandPool, 1, &commandBuffer);
        return false;
    }

    if (vkQueueSubmit(g_Queue, 1, &submitInfo, fence) != VK_SUCCESS) {
        vkDestroyFence(g_Device, fence, nullptr);
        vkFreeCommandBuffers(g_Device, g_CommandPool, 1, &commandBuffer);
        return false;
    }

    vkWaitForFences(g_Device, 1, &fence, VK_TRUE, UINT64_MAX);
    
    vkDestroyFence(g_Device, fence, nullptr);
    vkFreeCommandBuffers(g_Device, g_CommandPool, 1, &commandBuffer);
    
    return true;
}

static bool initializeImGui() {
    if (!createDescriptorPool()) return false;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2(g_SwapchainExtent.width, g_SwapchainExtent.height);

    if (!ImGui_ImplWin32_Init(g_NativeWindow)) {
        printf("Failed to initialize win32 backend\n");
        return false;
    }

    g_RenderPass = createImGuiRenderPass();
    if (g_RenderPass == VK_NULL_HANDLE) return false;

    createImGuiFramebuffers();
    if (g_Framebuffers.empty()) return false;

    ImGui_ImplVulkan_InitInfo init_info = {};
    init_info.Instance = g_Instance;
    init_info.PhysicalDevice = g_PhysicalDevice;
    init_info.Device = g_Device;
    init_info.QueueFamily = findGraphicsQueueFamily();
    init_info.Queue = g_Queue;
    init_info.RenderPass = g_RenderPass;
    init_info.PipelineCache = VK_NULL_HANDLE;
    init_info.DescriptorPool = g_DescriptorPool;
    init_info.MinImageCount = 2;
    init_info.ImageCount = g_SwapChainImages.size();
    init_info.MSAASamples = VK_SAMPLE_COUNT_1_BIT;
    init_info.Allocator = nullptr;
    init_info.CheckVkResultFn = nullptr;

    if (!ImGui_ImplVulkan_Init(&init_info)) return false;
    
    if (!uploadFonts()) return false;

    return true;
}

static void initRenderContexts() {
    printf("Initializing render contexts...\n");
    for (int i = 0; i < 2; i++) {
        g_RenderContexts[i].commandBuffer = createCommandBuffer();
        if (g_RenderContexts[i].commandBuffer == VK_NULL_HANDLE) {
            printf("Failed to create command buffer for context %d\n", i);
            continue;
        }
        
        VkFenceCreateInfo fenceInfo = {};
        fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;
        
        if (vkCreateFence(g_Device, &fenceInfo, nullptr, &g_RenderContexts[i].fence) != VK_SUCCESS) {
            printf("Failed to create fence for context %d\n", i);
            vkFreeCommandBuffers(g_Device, g_CommandPool, 1, &g_RenderContexts[i].commandBuffer);
            g_RenderContexts[i].commandBuffer = VK_NULL_HANDLE;
            continue;
        }
        
        g_RenderContexts[i].inUse = false;
        printf("Context %d initialized successfully\n", i);
    }
}

static PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR_Trampoline = NULL;

static VkResult vkCreateSwapchainKHR_Detour(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain
) {
    VkResult result = vkCreateSwapchainKHR_Trampoline(
        device,
        pCreateInfo,
        pAllocator,
        pSwapchain
    );

    if (result == VK_SUCCESS) {
        g_Swapchain = *pSwapchain;
        g_SwapchainExtent = pCreateInfo->imageExtent;
        g_Surface = pCreateInfo->surface;

        uint32_t imageCount;
        vkGetSwapchainImagesKHR(device, g_Swapchain, &imageCount, nullptr);
        g_SwapChainImages.resize(imageCount);
        vkGetSwapchainImagesKHR(device, g_Swapchain, &imageCount, g_SwapChainImages.data());
        
        printf(
            "Swapchain created successfully: %dx%d\n",
            g_SwapchainExtent.width, g_SwapchainExtent.height
        );

        if (
            !g_ImGuiInitialized && 
            !g_InitInProgress && 
            g_Device != VK_NULL_HANDLE && 
            g_Queue != VK_NULL_HANDLE &&
            g_NativeWindow
        ) {
            g_InitInProgress = true;
            
            if (initializeImGui()) {
                initRenderContexts();
                printf("Render contexts initialized successfully\n");

                g_ImGuiInitialized = true;
                printf("ImGui initialized successfully\n");
            } else {
                printf("Failed to initialize ImGui\n");
            }
            
            g_InitInProgress = false;
        }
    }

    return result;
}

static PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR_Trampoline = NULL;

static VkResult vkCreateWin32SurfaceKHR_Detour(
    VkInstance instance,
    const VkWin32SurfaceCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkSurfaceKHR* pSurface
) {
    printf("vkCreateWin32SurfaceKHR_Detour called!\n");

    if (!g_NativeWindow) {
        g_NativeWindow = pCreateInfo->hwnd;
        printf("g_NativeWindow = %p\n", (void *)g_NativeWindow);
    }

    return vkCreateWin32SurfaceKHR_Trampoline(
        instance,
        pCreateInfo,
        pAllocator,
        pSurface
    );
}

static PFN_vkCreateDevice vkCreateDevice_Trampoline = NULL;

static VkResult vkCreateDevice_Detour(
    VkPhysicalDevice physicalDevice,
    const VkDeviceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDevice* pDevice
) {
    printf("vkCreateDevice_Detour called\n");

    VkResult result = vkCreateDevice_Trampoline(
        physicalDevice, pCreateInfo, pAllocator, pDevice
    );

    if (result == VK_SUCCESS) {
        g_PhysicalDevice = physicalDevice;
        g_Device = *pDevice;

        // Get the graphics queue after device creation and create command pool
        uint32_t queueFamilyIndex = findGraphicsQueueFamily();
        vkGetDeviceQueue(g_Device, queueFamilyIndex, 0, &g_Queue);
        
        g_CommandPool = createCommandPool();
        if (g_CommandPool == VK_NULL_HANDLE) {
            printf("Failed to create command pool\n");
        }
    }

    return result;
}

PFN_vkQueueSubmit2 vkQueueSubmit2_Trampoline = NULL;

static VkResult vkQueueSubmit2_Detour(
    VkQueue queue,
    uint32_t submitCount,
    const VkSubmitInfo2* pSubmits,
    VkFence fence
) {
    if (g_InSubmit) { // Avoid recursion
        return vkQueueSubmit2_Trampoline(queue, submitCount, pSubmits, fence);
    }
    
    g_InSubmit = true;

    // First execute Unity rendering
    VkResult result = vkQueueSubmit2_Trampoline(queue, submitCount, pSubmits, fence);

    if (result != VK_SUCCESS) {
        printf("Original vkQueueSubmit2 failed\n");
        g_InSubmit = false;
        return result;
    }

    if (!g_ImGuiInitialized) {
        printf("ImGui not initialized yet\n");
        g_InSubmit = false;
        return result;
    }

    // Wait for the queue to be idle before rendering ImGui
    vkQueueWaitIdle(queue);

    try {
        RenderContext& currentContext = g_RenderContexts[g_CurrentContext];
        
        if (currentContext.commandBuffer == VK_NULL_HANDLE) {
            printf("Current context command buffer is null\n");
            return result;
        }

        if (currentContext.inUse) {
            if (vkWaitForFences(g_Device, 1, &currentContext.fence, VK_TRUE, 1000000) != VK_SUCCESS) {
                return result;
            }
            vkResetFences(g_Device, 1, &currentContext.fence);
        }

        vkResetCommandBuffer(currentContext.commandBuffer, 0);
        
        VkCommandBufferBeginInfo beginInfo = {};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
        
        if (vkBeginCommandBuffer(currentContext.commandBuffer, &beginInfo) != VK_SUCCESS) {
            printf("Failed to begin command buffer from current context\n");
            return result;
        }

        ImGui_ImplVulkan_NewFrame();
        ImGui_ImplWin32_NewFrame();
        
        gCallback();

        ImDrawData* draw_data = ImGui::GetDrawData();

        // FIXME: don't draw if window is hidden
        if (draw_data) {
            //LOGD("Drawing ImGui frame");

            uint32_t imageIndex = 0;
            // Get index of current image from command buffer, and use modulo to ensure it's within bounds
            if (pSubmits && pSubmits->commandBufferInfoCount > 0) {
                VkCommandBuffer cmdBuffer = pSubmits->pCommandBufferInfos[0].commandBuffer;
                imageIndex = reinterpret_cast<uintptr_t>(cmdBuffer) % g_Framebuffers.size();
            }

            VkRenderPassBeginInfo renderPassInfo = {};
            renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
            renderPassInfo.renderPass = g_RenderPass;
            renderPassInfo.framebuffer = g_Framebuffers[imageIndex];
            renderPassInfo.renderArea.offset = {0, 0};
            renderPassInfo.renderArea.extent = g_SwapchainExtent;

            vkCmdBeginRenderPass(currentContext.commandBuffer, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
            ImGui_ImplVulkan_RenderDrawData(draw_data, currentContext.commandBuffer);
            vkCmdEndRenderPass(currentContext.commandBuffer);
        }

        if (vkEndCommandBuffer(currentContext.commandBuffer) != VK_SUCCESS) {
            printf("Failed to end command buffer from current context\n");
            return result;
        }

        VkSubmitInfo submitInfo = {};
        submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submitInfo.commandBufferCount = 1;
        submitInfo.pCommandBuffers = &currentContext.commandBuffer;

        if (vkQueueSubmit(queue, 1, &submitInfo, currentContext.fence) != VK_SUCCESS) {
            printf("Failed to submit queue for ImGui rendering\n");
            //return result;
        }

        currentContext.inUse = true;
        g_CurrentContext = (g_CurrentContext + 1) % 2;

    } catch (const std::exception& e) {
        printf("ImGui rendering exception: %s\n", e.what());
    } catch (...) {
        printf("Unknown exception in ImGui rendering\n");
    }

    g_InSubmit = false;
    return result;
}

static int InitializeHooks() {
    if (CreateAndEnableHook(
        (void *)vkCreateDevice,
        (void *)vkCreateDevice_Detour,
        (void **)&vkCreateDevice_Trampoline
    ) < 0) {
        printf("CreateAndEnableHook vkCreateDevice failed!\n");
        return -1;
    }

    if (CreateAndEnableHook(
        (void *)vkCreateWin32SurfaceKHR,
        (void *)vkCreateWin32SurfaceKHR_Detour,
        (void **)&vkCreateWin32SurfaceKHR_Trampoline
    ) < 0) {
        printf("CreateAndEnableHook vkCreateWin32SurfaceKHR failed!\n");
        return -1;
    }

    if (CreateAndEnableHook(
        (void *)vkCreateSwapchainKHR,
        (void *)vkCreateSwapchainKHR_Detour,
        (void **)&vkCreateSwapchainKHR_Trampoline
    ) < 0) {
        printf("CreateAndEnableHook vkCreateSwapchainKHR failed\n!");
        return -1;
    }

    if (CreateAndEnableHook(
        (void *)vkQueueSubmit2,
        (void *)vkQueueSubmit2_Detour,
        (void **)&vkQueueSubmit2_Trampoline
    ) < 0) {
        printf("CreateAndEnableHook vkQueueSubmit2 failed\n!");
        return -1;
    }

    return 0;
}

static PFN_vkCreateInstance vkCreateInstance_Trampoline = NULL;

static VkResult vkCreateInstance_Detour(
    const VkInstanceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkInstance* pInstance
) {
    printf("vkCreateInstance_Detour called!!!\n");
    VkResult result = vkCreateInstance_Trampoline(
        pCreateInfo, pAllocator, pInstance
    );

    if (result == VK_SUCCESS) {
        g_Instance = *pInstance;
        volkLoadInstance(*pInstance);
        if (InitializeHooks() < 0) {
            printf("InitializeHooks failed!!!\n");
        }
    } else {
        printf("vkCreateInstance != VK_SUCCESS !!!\n");
    }

    return result;
}

int Backend_Load(std::function<void()> callback) {
    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetDC(hwnd);
    RECT textPos;
    textPos.left = 200;
    textPos.right = 200;
    textPos.top = 200;
    textPos.bottom = 200;
    char *text = "This is a test";
    while (true)
        DrawTextExA(hdc, text, strlen(text), &textPos, DT_CENTER | DT_NOCLIP | DT_NOPREFIX, NULL);

    return 1;
}

int Backend_Load2(std::function<void()> callback)
{

    gCallback = callback;

    if (volkInitialize() != VK_SUCCESS) {
        printf("Failed to initialize volk!!\n");
        return 0;
    }
   
    HMODULE vulkanModule = GetModuleHandleA("vulkan-1.dll");

    if (!vulkanModule) {
        printf("Failed to get vulkan-1.dll module");
        return 0;
    }

    vkCreateInstance = (PFN_vkCreateInstance)(uintptr_t)GetProcAddress(
        vulkanModule, "vkCreateInstance"
    );

    MH_Initialize();

    printf("vkCreateInstance: %p\n", (void *)vkCreateInstance);

    if (CreateAndEnableHook(
        (void *)vkCreateInstance,
        (void *)vkCreateInstance_Detour,
        (void **)&vkCreateInstance_Trampoline
    ) < 0) {
        printf("CreateAndEnableHook vkCreateInstance failed\n");
        return 0;
    }

	return 1;
}