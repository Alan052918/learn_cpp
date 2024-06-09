#include <iostream>
#include <utility>

#include "value_semantics/common/circle.h"
#include "value_semantics/common/draw.h"
#include "value_semantics/common/square.h"

int main() {
  // value semantics example: no pointers, no allocations, only values
  Shapes shapes;
  shapes.emplace_back(Circle{2.0});
  shapes.emplace_back(Square{1.5});
  shapes.emplace_back(Circle{4.2});

  DrawAllShape(shapes);
}
