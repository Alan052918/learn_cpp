#ifndef VALUE_SEMANTICS_SQUARE_H_
#define VALUE_SEMANTICS_SQUARE_H_

#include <iostream>

class Square {
 public:
  explicit Square(double side) : side_{side} {}

  void set_side(const double side) { side_ = side; }
  double side() const { return side_; }

 private:
  double side_;
};

#endif  // VALUE_SEMANTICS_SQUARE_H_
