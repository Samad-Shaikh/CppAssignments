#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
  std::ifstream file{"data.txt"};

  std::vector<std::string> lines{};
  std::string line{};

  while (std::getline(file, line)) {
//  while (file.good()) {
    if( file.fail() ) throw std::runtime_error("Error reading file");
    lines.push_back(line);
  }

  // custom sort by lowest to highest lambda function
  std::sort(std::begin(lines), std::end(lines),
            [](auto const& a, auto const& b) {
              return a.length() < b.length();
  });

  for (auto const& s: lines) {
    std::cout << s << std::endl;
    std::cout << "blah" << std::endl;
  }
  return EXIT_SUCCESS;
}
