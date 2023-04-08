#include "value_semantics/common/draw.h"

#include <variant>
#include <vector>

#include "value_semantics/common/circle.h"
#include "value_semantics/common/square.h"

void Draw::operator()(const Circle& circle) const {
  std::cout << "Draw a circle of radius " << circle.radius() << std::endl;
}

void Draw::operator()(const Square& square) const {
  std::cout << "Draw a square of side " << square.side() << std::endl;
}

void DrawAllShape(const std::vector<Shape>& shapes) {
  // modern visitor style:
  // - no inheritance hierarchy
  // - KISS (keep it simple, stupid)
  // - no virtual functions
  // - no pointers or indirections
  // - no manual dynamic memory allocation
  // - no need to manage lifetime
  // - no lifetime-related issues (no need for smart pointers)
  // - better performance
  for (const auto& shape : shapes) std::visit(Draw{}, shape);
}
