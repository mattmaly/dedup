#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_join.h"

// This is an arbitrary main file (for now) to verify that bazel is working
// properly with absl.
int main(int argc, char* argv[]) {
    std::vector<std::string> v = {"foo", "bar", "baz"};
    std::string s = absl::StrJoin(v, "-");
  
    std::cout << "Joined string: " << s << "\n";
  
    return 0;
}
