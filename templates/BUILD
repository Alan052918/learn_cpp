# Templates
# Reference: https://en.cppreference.com/w/cpp/language/templates

# common utility functions
cc_library(
    name = "common",
    hdrs = ["common/print_containers.h"],
    visibility = ["//visibility:public"],
    deps = ["//classes:common"],
)

cc_library(
    name = "lib",
    srcs = ["templates_lib.cc"],
    hdrs = ["templates_lib.h"],
    deps = ["//classes:common"],
)

cc_library(
    name = "lib_header_only",
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
    srcs = ["common/print_containers_test.cc"],
    deps = [
        "//templates:common",
        "@googletest//:gtest_main",
    ],
)
