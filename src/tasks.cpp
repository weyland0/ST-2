// Copyright 2022 UNN-CS
#include <utility>

#include "tasks.h"
#include "circle.h"

double resolveEarthAndCordTask() {
  const double EARTH_RADIUS = 6378.1 * 1000.0;
  Circle cord = Circle(EARTH_RADIUS);
  cord.setFerence(cord.getFerence() + 1.0);
  return cord.getRadius() - EARTH_RADIUS;
}

std::pair<double, double> resolvePoolTask() {
  const double CONCRETE_PATH_PRICE = 1000.0;
  const double FENCE_PRICE = 2000.0;
  const double POOL_RADIUS = 3.0;
  const double CONCRETE_PATH_WIDTH = 1.0;

  Circle pool = Circle(POOL_RADIUS);
  Circle pool_with_cp = Circle(POOL_RADIUS + CONCRETE_PATH_WIDTH);

  double cp_area = pool_with_cp.getArea() - pool.getArea();
  double cp_price = cp_area * CONCRETE_PATH_PRICE;

  Circle fence = Circle(POOL_RADIUS + CONCRETE_PATH_WIDTH);
  double fence_price = fence.getFerence() * FENCE_PRICE;

  return {cp_price, fence_price};
}
