# Templates
# Reference: https://en.cppreference.com/w/cpp/language/templates

# common utility functions
cc_library(
    name = "common",
    srcs = ["common/print_containers.cc"],
    hdrs = ["common/print_containers.h"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "templates",
    srcs = ["templates.cc"],
    deps = [
        "//classes:common",
        "//templates:common",
    ],
)

cc_test(
    name = "common_test",
    srcs = ["print_containers_unittest.cc"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//templates:common",
        "@gtest//:main",
    ],
)
