/*
Taken from https://github.com/zzzmate/IL2CPP-DirectX-ImGui-Base
*/

#include "Backend.h"

#include <functional>

#include <MinHook.h>

#include <windows.h>

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

#include <d3d11_1.h>

typedef long(__stdcall* presentVariable)(IDXGISwapChain*, UINT, UINT);

presentVariable originalPresent;
presentVariable hookedPresent;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static bool init = false;

ID3D11DeviceContext* m_gPointerContext = nullptr;
ID3D11RenderTargetView* m_gMainRenderTargetView = nullptr;
ID3D11Texture2D* m_gPointerBackBuffer = nullptr;
ID3D11Device* m_gDevice = nullptr;
DXGI_SWAP_CHAIN_DESC m_gSwapChainDescription{};
IDXGISwapChain* m_gSwapChain = nullptr;
const D3D_FEATURE_LEVEL m_gFeatureLevels[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0 };

WNDPROC m_goriginalWndProc;
DXGI_SWAP_CHAIN_DESC m_gPresentHookSwapChain;
D3D11_VIEWPORT m_gViewport;
HWND m_gWindow = NULL;

std::function<void()> gCallback;

bool DirectXPresentHook()
{
	ZeroMemory(&m_gSwapChainDescription, sizeof(m_gSwapChainDescription));

	m_gSwapChainDescription.BufferCount = 2;
	m_gSwapChainDescription.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	m_gSwapChainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	m_gSwapChainDescription.OutputWindow = GetForegroundWindow();
	m_gSwapChainDescription.SampleDesc.Count = 1;
	m_gSwapChainDescription.Windowed = TRUE;
	m_gSwapChainDescription.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	HRESULT createDevice = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, m_gFeatureLevels, 2, D3D11_SDK_VERSION, &m_gSwapChainDescription, &m_gSwapChain, &m_gDevice, nullptr, nullptr);
		
	if (FAILED(createDevice)) 
		return false; // dont return false make an endless cycle (only if u wanna go cpu boom) 

	void** DX11Vtable = *reinterpret_cast<void***>(m_gSwapChain);

	hookedPresent = (presentVariable)DX11Vtable[8]; // 8. virtual table is present

	return true;
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

	ImGuiIO& io = ImGui::GetIO();

	if (io.WantCaptureMouse || io.WantCaptureKeyboard) {
		return TRUE;
	}

	return CallWindowProc(m_goriginalWndProc, hWnd, uMsg, wParam, lParam);
}

void LoadImGui(HWND window, ID3D11Device* device, ID3D11DeviceContext* context)
{
	ImGui::CreateContext(); // creating the context cus we need imgui
	ImGui_ImplWin32_Init(window); // which window u wanna draw your imgui huh???
	ImGui_ImplDX11_Init(device, context); // u need the device's context since u can't draw with only device, thanx dx11
} // loading the imgui

void DrawImGui(ID3D11DeviceContext* context, ID3D11RenderTargetView* targetview)
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	
    gCallback();

	context->OMSetRenderTargets(1, &targetview, NULL);  // 1 render target, render it to our monitor, no dsv
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData()); // drawing the imgui menu
}

void InitInPresentHook(IDXGISwapChain* pointerSwapChain) {
    m_gDevice->GetImmediateContext(&m_gPointerContext); // need context immediately!!
    pointerSwapChain->GetDesc(&m_gPresentHookSwapChain); // welp we need the presenthook's outputwindow so it's actually ours o_o
    m_gWindow = m_gPresentHookSwapChain.OutputWindow;

    pointerSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&m_gPointerBackBuffer); // getting back buffer
    if (m_gPointerBackBuffer != nullptr)
        m_gDevice->CreateRenderTargetView(m_gPointerBackBuffer, NULL, &m_gMainRenderTargetView); // from backbuffer to our monitor

    m_gPointerBackBuffer->Release(); // don't need this shit anymore, but please comeback the next injection

    LoadImGui(m_gWindow, m_gDevice, m_gPointerContext); // load imgui!!!
    m_goriginalWndProc = (WNDPROC)SetWindowLongPtr(m_gWindow, GWLP_WNDPROC, (LONG_PTR)WndProc); // i think u need this
}

static long __stdcall PresentHook(IDXGISwapChain* pointerSwapChain, UINT sync, UINT flags)
{
	if (!init) {
		if (SUCCEEDED(pointerSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&m_gDevice))) // check if device working 
		{
			InitInPresentHook(pointerSwapChain);
			init = true;
		}
		else
			return originalPresent(pointerSwapChain, sync, flags); // returning original too
	}

	DrawImGui(m_gPointerContext, m_gMainRenderTargetView); // draw imgui every time
	return originalPresent(pointerSwapChain, sync, flags); // return the original so no stack corruption
}

int Backend_Load(std::function<void()> callback)
{
    gCallback = callback;

	DirectXPresentHook(); // this always okay if game directx11
	MH_Initialize(); // aint no error checking cuz if minhook bad then its your problem 

	MH_CreateHook(
        reinterpret_cast<void**>(hookedPresent),
        reinterpret_cast<void*>(&PresentHook),
        reinterpret_cast<void**>(&originalPresent)
    ); 
	MH_EnableHook(reinterpret_cast<void**>(hookedPresent), TRUE); // hooking present

	return 1;
}