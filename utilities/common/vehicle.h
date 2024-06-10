#ifndef UTILITIES_COMMON_VEHICLE_H_
#define UTILITIES_COMMON_VEHICLE_H_

#include <string>
#include <type_traits>
#include <variant>

#include "utilities/common/car.h"
#include "utilities/common/suv.h"
#include "utilities/common/truck.h"

namespace utilities {

using Vehicle = std::variant<Car, Truck, SUV>;

auto Start = [](Vehicle& vehicle) {
  std::visit([](auto& v) { v.Start(); }, vehicle);
};

auto Stop = [](Vehicle& vehicle) {
  std::visit([](auto& v) { v.Stop(); }, vehicle);
};

auto Accelerate = [](Vehicle& vehicle) {
  std::visit([](auto& v) { v.Accelerate(); }, vehicle);
};

auto Brake = [](Vehicle& vehicle) {
  std::visit([](auto& v) { v.Brake(); }, vehicle);
};

template <typename T>
auto LoadIfExists(int, T& vehicle) -> decltype(vehicle.Load(), void()) {
  vehicle.Load();
};

template <typename T>
void LoadIfExists(long, T& vehicle) {
  // Do nothing if load() doesn't exist
}

auto Load = [](Vehicle& vehicle) {
  std::visit([](auto& v) { LoadIfExists(0, v); }, vehicle);
};

template <typename T>
auto UnloadIfExists(int, T& vehicle) -> decltype(vehicle.unload(), void()) {
  vehicle.unload();
}

template <typename T>
void UnloadIfExists(long, T& vehicle) {
  // Do nothing if unload() doesn't exist
}

auto Unload = [](Vehicle& vehicle) {
  std::visit([](auto& v) { UnloadIfExists(0, v); }, vehicle);
};

template <typename T>
auto TowIfExists(int, T& vehicle) -> decltype(vehicle.tow(), void()) {
  vehicle.tow();
}

template <typename T>
void TowIfExists(long, T& vehicle) {
  // Do nothing if tow() doesn't exist
}

auto Tow = [](Vehicle& vehicle) {
  std::visit([](auto& v) { TowIfExists(0, v); }, vehicle);
};

auto GetName = [](Vehicle& vehicle) {
  return std::visit([](auto& v) { return v.name; }, vehicle);
};

auto GetColor = [](Vehicle& vehicle) {
  return std::visit([](auto& v) { return v.color; }, vehicle);
};

auto GetMake = [](Vehicle& vehicle) {
  return std::visit([](auto& v) { return v.make; }, vehicle);
};

}  // namespace utilities

#endif  // UTILITIES_COMMON_VEHICLE_H_
