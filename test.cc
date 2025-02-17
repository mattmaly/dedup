#include <string>
#include <vector>

#include "absl/strings/str_join.h"
#include "gtest/gtest.h"

TEST(Test, Example) {
  const std::vector<std::string> v = {"foo", "bar", "baz"};
  EXPECT_EQ(absl::StrJoin(v, "-"), "foo-bar-baz");
}
