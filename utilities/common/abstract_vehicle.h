#ifndef UTILITIES_COMMON_ABSTRACT_VEHICLE_H_
#define UTILITIES_COMMON_ABSTRACT_VEHICLE_H_

#include <string>

namespace utilities {

class AbstractVehicle {
 public:
  AbstractVehicle(const std::string& name, const std::string& color,
                  const std::string& make)
      : name(name), color(color), make(make) {}

  virtual void Start() = 0;
  virtual void Stop() = 0;
  virtual void Accelerate() = 0;
  virtual void Brake() = 0;

  const std::string name;
  const std::string color;
  const std::string make;
};

}  // namespace utilities

#endif  // UTILITIES_COMMON_ABSTRACT_VEHICLE_H_
