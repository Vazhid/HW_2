#include <gtest/gtest.h>
#include <string>
#include <stdio.h>
#include <sys/mman.h>
#include <dlfcn.h>

extern "C" {
    #include "foo.h"
}

TEST(groupe_A, first) {
    const char *str = "qwwerty";
    char *max_str;
    max_str = max_char(str, 7);
    ASSERT_STREQ("werty", max_str);
    free(max_str);
}

TEST(groupe_A, second) {
    const char *str = "qwerty";
    char *max_str;
    max_str = max_char(str, 6);
    ASSERT_STREQ("qwerty", max_str);
    free(max_str);
}

TEST(groupe_A, third) {
    const char *str = "cbaqqwbhvrjcwlcyyq";
    char *max_str;
    max_str = max_char(str, 18);
    ASSERT_STREQ("qwbhvrjcwlcy", max_str);
    free(max_str);
}

TEST(groupe_B, first) {
    const char *str = "qwwerty";
    char *max_str;
    max_str = parallel_max_char(str, 7);
    ASSERT_STREQ("werty", max_str);
    free(max_str);
}
TEST(groupe_B, second) {
    const char *str = "qwerty";
    char *max_str;
    max_str = parallel_max_char(str, 6);
    ASSERT_STREQ("qwerty", max_str);
    free(max_str);
}

TEST(groupe_B, third) {
    const char *str = "cbaqqwbhvrjcwlcyyq";
    char *max_str;
    max_str = parallel_max_char(str, 18);
    ASSERT_STREQ("qwbhvrjcwlcy", max_str);
    free(max_str);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
