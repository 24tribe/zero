#ifndef SAVES_HELPER_HPP_02_51_2025_13_12
#define SAVES_HELPER_HPP_02_51_2025_13_12

#include <string>
#include <vector>

enum SavesHelperStatus {
    SH_OK,
    SH_ERR_CREATE_DIR,
};

SavesHelperStatus GetSaveFiles(char *saves_dir, std::vector<std::string>& res);

#endif