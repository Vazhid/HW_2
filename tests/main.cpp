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
}

TEST(groupe_B, first) {
    const char *str = "qwwerty";
    char *max_str;
    max_str = parallel_max_char(str, 7);
    ASSERT_STREQ("werty", max_str);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
