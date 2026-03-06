// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

const double EPS = 1e-9;

TEST(CircleConstructor, ValidRadius) {
  Circle c(5.0);
  EXPECT_NEAR(c.getRadius(), 5.0, EPS);
  EXPECT_NEAR(c.getArea(), M_PI * 25.0, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 5.0, EPS);
}

TEST(CircleConstructor, ZeroRadius) {
  Circle c(0.0);
  EXPECT_EQ(c.getRadius(), 0.0);
  EXPECT_EQ(c.getArea(), 0.0);
  EXPECT_EQ(c.getFerence(), 0.0);
}

TEST(CircleConstructor, NegativeRadius) {
  EXPECT_THROW(Circle c(-1.0), std::invalid_argument);
}

TEST(SetRadius, Positive) {
  Circle c(1.0);
  c.setRadius(3.0);
  EXPECT_NEAR(c.getRadius(), 3.0, EPS);
  EXPECT_NEAR(c.getArea(), M_PI * 9.0, EPS);
  EXPECT_NEAR(c.getFerence(), 6 * M_PI, EPS);
}

TEST(SetRadius, Zero) {
  Circle c(10.0);
  c.setRadius(0.0);
  EXPECT_EQ(c.getRadius(), 0.0);
  EXPECT_EQ(c.getArea(), 0.0);
  EXPECT_EQ(c.getFerence(), 0.0);
}

TEST(SetRadius, Negative) {
  Circle c(5.0);
  EXPECT_THROW(c.setRadius(-2.0), std::invalid_argument);
  EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

TEST(SetFerence, Positive) {
  Circle c(2.0);
  double new_ference = 10.0;
  c.setFerence(new_ference);
  EXPECT_NEAR(c.getFerence(), new_ference, EPS);
  EXPECT_NEAR(c.getRadius(), new_ference / (2 * M_PI), EPS);
  EXPECT_NEAR(c.getArea(), M_PI * pow(new_ference / (2 * M_PI), 2), EPS);
}

TEST(SetFerence, Zero) {
  Circle c(4.0);
  c.setFerence(0.0);
  EXPECT_EQ(c.getFerence(), 0.0);
  EXPECT_EQ(c.getRadius(), 0.0);
  EXPECT_EQ(c.getArea(), 0.0);
}

TEST(SetFerence, Negative) {
  Circle c(3.0);
  EXPECT_THROW(c.setFerence(-5.0), std::invalid_argument);
  EXPECT_NEAR(c.getFerence(), 6 * M_PI, EPS);
}

TEST(SetArea, Positive) {
  Circle c(1.0);
  double new_area = 28.27433388;
  c.setArea(new_area);
  EXPECT_NEAR(c.getArea(), new_area, EPS);
  EXPECT_NEAR(c.getRadius(), 3.0, EPS);
  EXPECT_NEAR(c.getFerence(), 6 * M_PI, EPS);
}

TEST(SetArea, Zero) {
  Circle c(5.0);
  c.setArea(0.0);
  EXPECT_EQ(c.getArea(), 0.0);
  EXPECT_EQ(c.getRadius(), 0.0);
  EXPECT_EQ(c.getFerence(), 0.0);
}

TEST(SetArea, Negative) {
  Circle c(2.0);
  EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
  EXPECT_NEAR(c.getArea(), 4 * M_PI, EPS);
}

TEST(Getters, ConsistentValues) {
  Circle c(10.0);
  EXPECT_NEAR(c.getArea(), M_PI * 100.0, EPS);
  EXPECT_NEAR(c.getFerence(), 20 * M_PI, EPS);
  EXPECT_NEAR(c.getRadius(), 10.0, EPS);
}

TEST(SetRadius, Consistency) {
  Circle c(1.0);
  c.setRadius(7.0);
  EXPECT_NEAR(c.getArea() / M_PI, pow(c.getRadius(), 2), EPS);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * c.getRadius(), EPS);
}

TEST(SetFerence, Consistency) {
  Circle c(1.0);
  c.setFerence(12.5663706144);
  EXPECT_NEAR(c.getRadius(), 2.0, EPS);
  EXPECT_NEAR(c.getArea(), 4 * M_PI, EPS);
}

TEST(SetArea, Consistency) {
  Circle c(1.0);
  c.setArea(12.5663706144);
  EXPECT_NEAR(c.getRadius(), 2.0, EPS);
  EXPECT_NEAR(c.getFerence(), 4 * M_PI, EPS);
}

TEST(Setters, OrderIndependent) {
  Circle c(5.0);
  c.setArea(78.5398163397);
  c.setRadius(5.0);
  c.setFerence(31.4159265359);
  EXPECT_NEAR(c.getRadius(), 5.0, EPS);
  EXPECT_NEAR(c.getArea(), 25 * M_PI, EPS);
  EXPECT_NEAR(c.getFerence(), 10 * M_PI, EPS);
}

TEST(CircleConstructor, LowPrecision) {
  Circle c(0.000001);
  EXPECT_NEAR(c.getArea(), M_PI * 1e-12, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e-6, EPS);
}

TEST(CircleConstructor, LargeRadius) {
  Circle c(10000.0);
  EXPECT_NEAR(c.getArea(), M_PI * 10000.0 * 10000.0, EPS);
  EXPECT_NEAR(c.getFerence(), 20000 * M_PI, EPS);
}

TEST(Getters, NoThrow) {
  Circle c(3.14);
  EXPECT_NO_THROW(c.getRadius());
  EXPECT_NO_THROW(c.getArea());
  EXPECT_NO_THROW(c.getFerence());
}

TEST(SetRadius, ThrowMessage) {
  Circle c(1.0);
  try {
    c.setRadius(-1.0);
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &ex) {
    EXPECT_STREQ(ex.what(), "Radius can not be less than zero.");
  }
}

TEST(SetFerence, ThrowMessage) {
  Circle c(1.0);
  try {
    c.setFerence(-1.0);
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &ex) {
    EXPECT_STREQ(ex.what(), "Ference can not be less than zero.");
  }
}

TEST(SetArea, ThrowMessage) {
  Circle c(1.0);
  try {
    c.setArea(-1.0);
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument &ex) {
    EXPECT_STREQ(ex.what(), "Area can not be less than zero.");
  }
}

TEST(Tasks, EarthCordGapCorrect) {
  double gap = resolveEarthAndCordTask();
  EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-6);
  EXPECT_GT(gap, 0.15);
  EXPECT_LT(gap, 0.16);
}

TEST(Tasks, EarthCordPositiveGap) {
  double gap = resolveEarthAndCordTask();
  EXPECT_GT(gap, 0.0);
}

TEST(Tasks, EarthCordIndependentOfRadius) {
  double gap = resolveEarthAndCordTask();
  EXPECT_NEAR(gap, 0.159154943, 1e-6);
}

TEST(Tasks, PoolConcretePathAreaCorrect) {
  auto [cp_price, fence_price] = resolvePoolTask();
  double expected_area = M_PI * (4.0 * 4.0 - 3.0 * 3.0);
  double expected_cp_price = expected_area * 1000.0;
  EXPECT_NEAR(cp_price, expected_cp_price, 1e-6);
  EXPECT_NEAR(cp_price, 21991.148575, 1);
}

TEST(Tasks, PoolFenceLengthCorrect) {
  auto [cp_price, fence_price] = resolvePoolTask();
  double expected_ference = 2 * M_PI * 4.0;
  double expected_fence_price = expected_ference * 2000.0;
  EXPECT_NEAR(fence_price, expected_fence_price, 1e-6);
  EXPECT_NEAR(fence_price, 50265.482457, 1);
}

TEST(Tasks, PoolPricesPositive) {
  auto [cp_price, fence_price] = resolvePoolTask();
  EXPECT_GT(cp_price, 0.0);
  EXPECT_GT(fence_price, 0.0);
}

TEST(Tasks, PoolTotalCost) {
  auto [cp_price, fence_price] = resolvePoolTask();
  double total = cp_price + fence_price;
  EXPECT_NEAR(total, 72256.631, 1);
}

TEST(Tasks, EarthCordPrecision) {
  double gap = resolveEarthAndCordTask();
  EXPECT_NEAR(gap * 2 * M_PI, 1.0, 1e-9);
}

TEST(Tasks, PoolFenceUsesOuterRadius) {
  auto [cp_price, fence_price] = resolvePoolTask();
  double outer_ference = 2 * M_PI * 4.0;
  EXPECT_NEAR(fence_price / 2000.0, outer_ference, 1e-6);
}
