#include <limits.h>
#include "gtest/gtest.h"
#include "lib/cmath.h"

class Math : public ::testing::Test {
protected:
    CalcMath math;
    const double abs = 1e-8;
};

// CalcMath.add tests
TEST_F(Math, Addition) {
    // equal
    ASSERT_EQ(math.add(5, 25), 30);
    EXPECT_EQ(math.add(0, 0), 0);
    EXPECT_EQ(math.add(-0, -0), 0);
    EXPECT_EQ(math.add(-5, 0), -5);
    EXPECT_EQ(math.add(-20, -85), -105);
    EXPECT_EQ(math.add(-25, 5), -20);
    EXPECT_EQ(math.add(25, 5000), 5025);
    EXPECT_EQ(math.add(1000000, 1000000), 2000000);
    
    // floating point
    ASSERT_EQ(math.add(0, 0.25), 0.25);
    EXPECT_EQ(math.add(0.5, 0.5), 1);
    EXPECT_EQ(math.add(-1.25, -0.25), -1.5);
    EXPECT_NEAR(math.add(-25, 25.2657), 0.2657, abs);
    EXPECT_EQ(math.add(3.14159, -3.14159), 0);
    
    // not equal
    ASSERT_NE(math.add(-5, -5), -5);
    EXPECT_NE(math.add(-5, -5), 5);
    EXPECT_NE(math.add(-1, -5), 4);
    EXPECT_NE(math.add(-1, -5), -4);
    EXPECT_NE(math.add(0, 0.00000001), 0);
}


TEST_F(Math, Subtraction) {
    // equal
    ASSERT_EQ(math.sub(5, 25), -20);
    EXPECT_EQ(math.sub(0, 0), 0);
    EXPECT_EQ(math.sub(-0, -0), 0);
    EXPECT_EQ(math.sub(25, 30), -5);
    EXPECT_EQ(math.sub(15, 6), 9);
    EXPECT_EQ(math.sub(-25, -25), 0);
    EXPECT_EQ(math.sub(-5, 0), -5);
    EXPECT_EQ(math.sub(-25, 5), -30);
    EXPECT_EQ(math.sub(1000000, 20000000), -19000000);
    
    // floating point
    ASSERT_EQ(math.sub(0, 0.25), -0.25);
    EXPECT_EQ(math.sub(0.5, 0.5), 0);
    EXPECT_EQ(math.sub(-0.5, 0.5), -1);
    EXPECT_EQ(math.sub(-0.5, -0.5), 0);
    EXPECT_EQ(math.sub(1.25, 0.25), 1);
    EXPECT_NEAR(math.sub(-25, 25.2657), -0.2657, abs);
    EXPECT_EQ(math.sub(3.14159, 3.14159), 0);
    
    // not equal
    ASSERT_NE(math.sub(-5, 5), -5);
    EXPECT_NE(math.sub(10, -10), 0);
    EXPECT_NE(math.sub(-1, 1), 0);
    EXPECT_NE(math.sub(5, -5), -5);
    EXPECT_NE(math.sub(0, 0.000000001), 0);
}

TEST_F(Math, Multiplication) {
    // equal
    ASSERT_EQ(math.mult(5, 5), 25);
    EXPECT_EQ(math.mult(0, 0), 0);
    EXPECT_EQ(math.mult(-5, -5), 25);
    EXPECT_EQ(math.mult(-5, 5), -25);
    EXPECT_EQ(math.mult(7, 7), 49);
    EXPECT_EQ(math.mult(10, 10), 100);
    EXPECT_EQ(math.mult(1000, 1000), 1000000);
    EXPECT_EQ(math.mult(-1000, 1000), -1000000);
    EXPECT_EQ(math.mult(0, 5000), 0);

    // floating point
    ASSERT_EQ(math.mult(0, 0.25), 0);
    EXPECT_EQ(math.mult(0.25, 4), 1);
    EXPECT_EQ(math.mult(0.5, -2), -1);
    EXPECT_EQ(math.mult(25.5, 2), 51);
    EXPECT_NEAR(math.mult(1.567, 2.657), 4.163519, abs);
    EXPECT_NEAR(math.mult(2, 3.14159), 6.28318, abs);

    // not equal
    ASSERT_NE(math.mult(0, 0), 1);
    EXPECT_NE(math.mult(1, -2), 2);
    EXPECT_NE(math.mult(-1, -2), -2);
    EXPECT_NE(math.mult(-1, 2), 2);
}

TEST_F(Math, Division) {
    // equal
    ASSERT_EQ(math.div(1, 1), 1);
    EXPECT_EQ(math.div(2, 1), 2);
    EXPECT_EQ(math.div(25, 5), 5);
    EXPECT_EQ(math.div(-100, 1), -100);
    EXPECT_EQ(math.div(100, -1), -100);
    EXPECT_EQ(math.div(-100, -1), 100);
    EXPECT_EQ(math.div(0, 2), 0);

    // floating point
    ASSERT_EQ(math.div(1, 2), 0.5);
    EXPECT_EQ(math.div(5, 2), 2.5);
    EXPECT_EQ(math.div(-5, 2), -2.5);
    EXPECT_NEAR(math.div(-5, 3), -1.66666666, abs); // Mozno bude problem
    EXPECT_NEAR(math.div(5, 3), 1.66666666, abs);
    EXPECT_EQ(math.div(3.14159, 3.14159), 0);

    // not equal
    ASSERT_NE(math.div(5, 5), 0);
    EXPECT_NE(math.div(-5, -5), -1);
    EXPECT_NE(math.div(-5, 5), 1);
    EXPECT_NE(math.div(3.14159, -1), 3.14159);
    
    // false
    EXPECT_FALSE(math.div(2, 0));
}

TEST_F(Math, Exponentiation) {
    // equal
    ASSERT_EQ(math.pow(2, 2), 4);
    EXPECT_EQ(math.pow(0, 1), 0);
    EXPECT_EQ(math.pow(0, 0), 1);
    EXPECT_EQ(math.pow(500, 0), 1);
    EXPECT_EQ(math.pow(-500, 0), 1);
    EXPECT_EQ(math.pow(3, 3), 27);
    EXPECT_EQ(math.pow(-2, 2), 4);
    EXPECT_EQ(math.pow(-2, 3), -8);
    EXPECT_EQ(math.pow(10, 5), 100000);

    // floating point
    ASSERT_EQ(math.pow(0.5, 2), 0.25);
    EXPECT_EQ(math.pow(2, -2), 0.25);
    EXPECT_EQ(math.pow(-2, -2), -0.25);
    EXPECT_NEAR(math.pow(6, -2), 0.027777, abs); // mozno bude problem
    EXPECT_NEAR(math.pow(3.14159, 3.14159), 36.46195209, abs);

    // not equal
    ASSERT_NE(math.pow(2, 3), 6);
    EXPECT_NE(math.pow(2, 5), 10);
    EXPECT_NE(math.pow(2, -5), -10);
    EXPECT_NE(math.pow(-2, 2), -4);
    EXPECT_NE(math.pow(-2, 3), 8);
}

TEST_F(Math, SquareRoot) {
    // equal
    ASSERT_EQ(math.root(2, 4), 2);
    EXPECT_EQ(math.root(2, 0), 0);
    EXPECT_EQ(math.root(2, 9), 3);
    EXPECT_EQ(math.root(3, 27), 3);
    EXPECT_EQ(math.root(3, -8), -2);
    EXPECT_EQ(math.root(2, 1000000), 1000);
    
    // floating point
    ASSERT_NEAR(math.root(2, 2), 1.414213562, abs);
    ASSERT_NEAR(math.root(2, 8), 2.828427125, abs);

    // not equal

    // false
    ASSERT_FALSE(math.root(2, -1));
    ASSERT_FALSE(math.root(4, -1));
}