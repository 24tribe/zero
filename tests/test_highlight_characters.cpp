#include "../gui/HighlightCharacters.hpp"

#include <iostream>
#include <cstdlib>

#define DO_ASSERT(x) do { \
  if (!(x)) { \
    std::cerr << __FILE__ << ":" << __LINE__ << ": `" << #x << "` assertion failed!\n"; \
    abort(); \
  } \
} while (0)


int main() {
  std::vector<size_t> positions = {0, 1, 6};
  std::string s = "Hello ñandu world と😂";
  auto res = HighlightCharacters(s, positions, "#F0F");
  std::cout << res << '\n';
  DO_ASSERT(res == "^[#F0F]He^[#]llo ^[#F0F]ñ^[#]andu world と😂");
}
