#include "SavesHelper.hpp"

#include <string>
#include <filesystem>

namespace fs = std::filesystem;

SavesHelperStatus GetSaveFiles(char *saves_dir, std::vector<std::string>& res) {
    std::error_code ec;
    fs::create_directory(saves_dir, ec);
    if (ec.value()) {
        return SH_ERR_CREATE_DIR;
    }
    for (const auto & entry : fs::directory_iterator(saves_dir)) {
        res.push_back(entry.path().stem().string());
    }
    return SH_OK;
}