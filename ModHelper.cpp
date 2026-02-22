#include "ModHelper.h"

#include <windows.h>

#include <jansson.h>

#include <unordered_map>
#include <memory>
#include <cstdio>
#include <filesystem>
#include <unordered_set>
#include <optional>
#include <string>

namespace fs = std::filesystem;

using TextureMap = std::unordered_map<std::string, std::string>;
using BundleMap = std::unordered_map<std::string, TextureMap>;

struct ModManager {
    BundleMap bundles;
};

static void addJsonModToBundles(
    BundleMap& bundles, std::unordered_set<fs::path> subDirPaths,
    const fs::path modDir, json_t *modJson
) {
    for (void *it = json_object_iter(modJson); it != NULL; it = json_object_iter_next(modJson, it)) {
        const char *bundleName = json_object_iter_key(it);
        json_t *textureNames = json_object_iter_value(it);
        TextureMap textureMap;
        if (auto search = bundles.find(bundleName); search != bundles.end()) {
            textureMap = search->second;
        }
        size_t size = json_array_size(textureNames);
        for (size_t i = 0; i < size; ++i) {
            json_t *textureName = json_array_get(textureNames, i);
            auto texName = std::string(json_string_value(textureName));
            auto texPath = modDir/(texName+".png");
            if (auto texSearch = subDirPaths.find(texPath); texSearch != subDirPaths.end()) {
                textureMap.insert_or_assign(texName, (*texSearch).string());
            } else {
                printf("Warning: %s texture doesn't exist\n", texPath.string().c_str());
            }
        }
        bundles.insert_or_assign(bundleName, textureMap);
    }
}

static void addModToBundles(BundleMap& bundles, const fs::path modDir) {
    std::unordered_set<fs::path> subDirPaths;
    std::optional<fs::path> modFilePath = std::nullopt;
    for (const auto & subEntry : fs::directory_iterator(modDir)) {
        subDirPaths.insert(subEntry.path());
        if (subEntry.path().extension() == ".modfile") {
            modFilePath = std::optional<fs::path>(subEntry.path());
        }
    }

    if (modFilePath) {
        auto path = *modFilePath;
        json_error_t error;
        json_t *modJson = json_load_file(path.string().c_str(), 0, &error);
        if (modJson) {
            addJsonModToBundles(bundles, subDirPaths, modDir, modJson);
            free(modJson);
        } else {
            printf("Error: failed to load '%s' modfile json\n", path.string().c_str());
            printf("%s: %s\n", error.source, error.text);
        }
    } else {
        printf("Warning: didn't find a .modfile inside '%s' directory\n", modDir.string().c_str());
    }
}

extern "C" ModManager *ModHelper_ParseMods(const char *modsPath) {
    auto mgr = std::make_unique<ModManager>();

    std::error_code ec;
    fs::create_directory(modsPath, ec);
    if (ec.value()) {
        printf("fs::create_directory failed!!\n");
        return NULL;
    }
    for (const auto & entry : fs::directory_iterator(modsPath)) {
        if (entry.is_directory()) {
            addModToBundles((*mgr).bundles, entry.path());
        }
    }

    return mgr.release();
}

extern "C" char *ModHelper_GetTextureChanges(ModManager *mgr, const char *bundlePath) {
    const fs::path path(bundlePath);
    const auto bundleName = path.stem().string();

    if (auto search = mgr->bundles.find(bundleName); search != mgr->bundles.end()) {
        auto textureMap = search->second;
        json_t *textureChanges = json_object();
        for (const auto& [textureName, texturePath] : textureMap) {
            json_object_set_new(textureChanges, textureName.c_str(), json_string(texturePath.c_str()));
        }
        char *res = json_dumps(textureChanges, 0);
        json_decref(textureChanges);
        return res;
    } else {
        return NULL;
    }
}

extern "C" wchar_t *ModHelper_GetPathForNewBundle(const char *bundlePath) {
    const fs::path path(bundlePath);
    const auto filename = path.filename();

#define TEMP_PATH_SIZE 261

    wchar_t tempPath[TEMP_PATH_SIZE] = {0};

    DWORD size = GetTempPathW(TEMP_PATH_SIZE, tempPath);

    if (size != 0 && size < TEMP_PATH_SIZE) {
        const fs::path basePath(tempPath);
        const fs::path resultPath = basePath / filename;
        const auto resultStr = resultPath.wstring();
        size_t bytesSize = 2*(resultStr.length() + 1);
        auto result = reinterpret_cast<wchar_t *>(malloc(bytesSize));
        memcpy(result, resultStr.c_str(), bytesSize);
        return result;
    }

    return NULL;
}