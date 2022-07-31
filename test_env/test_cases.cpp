#define GOOGLE_TEST_MODULE test_version

#include "../lib.h"
#include <gtest/gtest.h>

TEST (VersionTest, VersionIsPositive) {
    ASSERT_GT(0, version());
}

