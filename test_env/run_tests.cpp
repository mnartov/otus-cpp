#define GOOGLE_TEST_MODULE test_version

#include <gtest/gtest.h>

int main(int argc, char∗∗ argv) {
  ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

