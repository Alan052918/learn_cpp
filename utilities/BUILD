# Sum types and type erased wrappers
# Reference: https://en.cppreference.com/w/cpp/utility

cc_library(
    name = "common",
    hdrs = [
        "common/abstract_vehicle.h",
        "common/car.h",
        "common/suv.h",
        "common/truck.h",
        "common/vehicle.h",
    ],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "sum_type",
    srcs = ["sum_type_demo.cc"],
    deps = [
        "//utilities:common",
    ],
)
