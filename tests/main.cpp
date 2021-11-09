#include <gtest/gtest.h>
#include <string>
#include <sys/mman.h>
#include <dlfcn.h>

extern "C" {
    #include "foo.h"
}

TEST(groupe_A, first) {
    EXPECT_EQ("qw", "qw");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
