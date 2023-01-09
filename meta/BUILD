# Metaprogramming library
# Reference: https://en.cppreference.com/w/cpp/meta

cc_library(
    name = "common",
    hdrs = ["common/print_containers.h"],
    visibility = ["//visibility:public"],
    deps = ["//classes:common"],
)

cc_binary(
    name = "meta",
    srcs = ["meta_demo.cc"],
    deps = [
        "//classes:common",
        "//meta:common",
    ],
)

cc_test(
    name = "common_test",
    srcs = ["common/print_containers_test.cc"],
    deps = [
        "//classes:common",
        "//meta:common",
        "@com_google_googletest//:gtest_main",
    ],
)
