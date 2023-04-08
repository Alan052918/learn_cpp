#ifndef VALUE_SEMANTICS_DRAW_H_
#define VALUE_SEMANTICS_DRAW_H_

#include <utility>
#include <vector>

#include "value_semantics/common/circle.h"
#include "value_semantics/common/square.h"

class Draw {
 public:
  void operator()(const Circle& circle) const;
  void operator()(const Square& square) const;
};

// value semantics example
using Shape = std::variant<Circle, Square>;
using Shapes = std::vector<Shape>;

void DrawAllShape(const std::vector<Shape>& shapes);

#endif  // VALUE_SEMANTICS_DRAW_H_
