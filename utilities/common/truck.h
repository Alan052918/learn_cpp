#ifndef UTILITIES_COMMON_TRUCK_H_
#define UTILITIES_COMMON_TRUCK_H_

#include "utilities/common/abstract_vehicle.h"

namespace utilities {

class Truck : public AbstractVehicle {
 public:
  Truck(const std::string& name, const std::string& color,
        const std::string& make, int load_capacity, int towing_capacity);

  void Start() override;
  void Stop() override;
  void Accelerate() override;
  void Brake() override;

  void Load();
  void Unload();

  void Tow();
  void Untow();

  int load_capacity;
  int towing_capacity;
};

}  // namespace utilities

#endif  // UTILITIES_COMMON_TRUCK_H_
