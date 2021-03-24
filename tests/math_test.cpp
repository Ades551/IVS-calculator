#include <limits.h>
#include "gtest/gtest.h"
#include "lib/math.h"

class Math : public ::testing::Test {
protected:
    CalcMath math;
};

TEST_F(Math, Addition) {
    EXPECT_EQ(math.add(5, 25), 30);
}