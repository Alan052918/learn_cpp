# Templates
# Reference: https://en.cppreference.com/w/cpp/language/templates

# common utility functions
cc_library(
    name = "common",
    srcs = ["common/print_containers.cc"],
    hdrs = ["common/print_containers.h"],
    visibility = ["//visibility:public"],
    deps = ["//classes:common"],
)

cc_library(
    name = "lib",
    srcs = ["templates_lib.h", "templates_lib.cc",],
    hdrs = ["templates_lib.h"],
)

cc_binary(
    name = "templates",
    srcs = ["templates_demo.cc"],
    deps = [
        "//classes:common",
        "//templates:common",
        "//templates:lib",
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
