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
