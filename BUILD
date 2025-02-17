load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_test")

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["@abseil-cpp//absl/strings"],
)

cc_test(
    name = "test",
    srcs = ["test.cc"],
    deps = [
        "@abseil-cpp//absl/strings",
        "@googletest//:gtest_main",
    ],
)
