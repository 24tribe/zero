#pragma once

#include <string>
#include <vector>

std::string HighlightCharacters(
  std::string_view text, const std::vector<size_t> positions, std::string_view color = "#F0F"
);
