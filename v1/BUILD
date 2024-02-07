
cc_library(
    name='messaging-lib',
    srcs = glob(['*.cpp']),
    hdrs = glob(['*.h']),
)

cc_binary(
    name='messaging-test',
    srcs = glob(['main.cpp']),
    deps = [':messaging-lib',],
)
