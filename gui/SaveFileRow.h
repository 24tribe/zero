#pragma once

#include <string>
#include <vector>
#include <cstddef>

struct SaveFileRow {
    std::string name;
    int fuzzyScore;  
    std::vector<size_t> positions;
};
