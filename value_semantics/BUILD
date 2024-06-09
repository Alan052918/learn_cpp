# Value Semantics
# Reference: https://www.youtube.com/watch?v=G9MxNwUoSt0&t=855s

# common class definitions
cc_library(
    name = "common",
    srcs = ["common/draw.cc"],
    hdrs = [
        "common/circle.h",
        "common/draw.h",
        "common/square.h",
    ],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "value_semantics",
    srcs = ["value_semantics.cc"],
    deps = ["//value_semantics:common"],
)
