#ifndef VALUE_SEMANTICS_CIRCLE_H_
#define VALUE_SEMANTICS_CIRCLE_H_

#include <iostream>

class Circle {
 public:
  explicit Circle(double radius) : radius_{radius} {}

  void set_radius(const double radius) { radius_ = radius; }
  double radius() const { return radius_; }

 private:
  double radius_;
};

#endif  // VALUE_SEMANTICS_CIRCLE_H_
