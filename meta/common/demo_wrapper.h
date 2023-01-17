#ifndef META_COMMON_DEMO_WRAPPER_H_
#define META_COMMON_DEMO_WRAPPER_H_

#include <iostream>
#include <string>
#include <type_traits>

namespace demo {

void EnterScope(const std::string& name) {
  std::cout << std::endl << " --- " << name << " enter scope --- " << std::endl;
}

void ExitScope(const std::string& name) {
  std::cout << std::endl << " --- " << name << " exit scope --- " << std::endl;
}

}  // namespace demo

#endif  // META_COMMON_DEMO_WRAPPER_H_
