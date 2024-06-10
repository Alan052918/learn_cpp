#include "utilities/common/car.h"

#include <iostream>

#include "utilities/common/abstract_vehicle.h"

utilities::Car::Car(const std::string& name, const std::string& color,
                    const std::string& make)
    : AbstractVehicle(name, color, make) {}

void utilities::Car::Start() { std::cout << "Car started" << std::endl; }

void utilities::Car::Stop() { std::cout << "Car stopped" << std::endl; }

void utilities::Car::Accelerate() {
  std::cout << "Car accelerated" << std::endl;
}

void utilities::Car::Brake() { std::cout << "Car braked" << std::endl; }
