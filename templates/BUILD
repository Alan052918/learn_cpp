# Templates
# Reference: https://en.cppreference.com/w/cpp/language/templates

# common utility functions
cc_library(
    name = "common",
    srcs = ["common/print_containers.h"],
    hdrs = ["common/print_containers.h"],
    visibility = ["//visibility:public"],
    deps = ["//classes:common"],
)

cc_library(
    name = "lib",
    srcs = [
        "templates_lib.cc",
        "templates_lib.h",
    ],
    hdrs = ["templates_lib.h"],
)

cc_library(
    name = "lib_header_only",
    srcs = ["templates_lib_header_only.h"],
    hdrs = ["templates_lib_header_only.h"],
)

cc_binary(
    name = "templates",
    srcs = ["templates_demo.cc"],
    deps = [
        "//classes:common",
        "//templates:common",
        "//templates:lib_header_only",
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
