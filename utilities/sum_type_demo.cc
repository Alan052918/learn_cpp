#include <iostream>

#include "utilities/common/vehicle.h"

int main() {
  utilities::Vehicle car = utilities::Car("Carlos", "Red", "Toyota");
  utilities::Start(car);
  std::cout << utilities::GetName(car) << std::endl;
}
