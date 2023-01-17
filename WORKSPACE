workspace(name = "learn_cpp")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

GOOGLETEST_COMMIT = "5ab508a01f9eb089207ee87fd547d290da39d015"

GOOGLETEST_SHA256 = "755f9a39bc7205f5a0c428e920ddad092c33c8a1b46997def3f1d4a82aded6e1"

http_archive(
    name = "com_google_googletest",  # 2022-12-20T09:25:53Z
    sha256 = GOOGLETEST_SHA256,
    strip_prefix = "googletest-%s" % GOOGLETEST_COMMIT,
    urls = ["https://github.com/google/googletest/archive/%s.zip" % GOOGLETEST_COMMIT],
)
