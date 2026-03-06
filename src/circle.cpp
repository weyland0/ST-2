// Copyright 2022 UNN-CS
#include <cmath>
#include <stdexcept>

#include "circle.h"

Circle::Circle(double radius) { setRadius(radius); }

void Circle::setRadius(double radius) {
  if (radius < 0) {
    throw std::invalid_argument("Radius can not be less than zero.");
  }

  radius_ = radius;
  area_ = M_PI * radius_ * radius_;
  ference_ = 2.0 * M_PI * radius_;
}

void Circle::setFerence(double ference) {
  if (ference < 0) {
    throw std::invalid_argument("Ference can not be less than zero.");
  }

  ference_ = ference;
  radius_ = ference_ / (2 * M_PI);
  area_ = M_PI * radius_ * radius_;
}

void Circle::setArea(double area) {
  if (area < 0) {
    throw std::invalid_argument("Area can not be less than zero.");
  }

  area_ = area;
  radius_ = std::sqrt(area_ / M_PI);
  ference_ = 2.0 * M_PI * radius_;
}

double Circle::getRadius() const noexcept { return radius_; }

double Circle::getFerence() const noexcept { return ference_; }

double Circle::getArea() const noexcept { return area_; }
