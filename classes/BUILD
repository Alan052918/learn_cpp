# C++ language - Classes
# Reference: https://en.cppreference.com/w/cpp/language/classes

# common class definitions
cc_library(
    name = "common",
    srcs = [
        "common/book.cc",
        "common/file_handle.cc",
        "common/person.cc",
        "common/student.cc",
    ],
    hdrs = [
        "common/book.h",
        "common/file_handle.h",
        "common/person.h",
        "common/student.h",
    ],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "classes",
    srcs = ["classes_demo.cc"],
    deps = [
        "//classes:common",
        "//meta:common",
    ],
)
