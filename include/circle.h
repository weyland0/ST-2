// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 public:
  explicit Circle(double radius);

  void setRadius(double radius);
  void setFerence(double ference);
  void setArea(double area);
  double getRadius() const noexcept;
  double getFerence() const noexcept;
  double getArea() const noexcept;

 private:
  double radius_;
  double ference_;
  double area_;
};

#endif // INCLUDE_CIRCLE_H_
