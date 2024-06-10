#ifndef UTILITIES_COMMON_CAR_H_
#define UTILITIES_COMMON_CAR_H_

#include "utilities/common/abstract_vehicle.h"

namespace utilities {

class Car : public AbstractVehicle {
 public:
  Car(const std::string& name, const std::string& color,
      const std::string& make);

  void Start() override;
  void Stop() override;
  void Accelerate() override;
  void Brake() override;
};

}  // namespace utilities

#endif  // UTILITIES_COMMON_CAR_H_
