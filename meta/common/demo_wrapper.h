#ifndef META_COMMON_DEMO_WRAPPER_H_
#define META_COMMON_DEMO_WRAPPER_H_

#include <iostream>
#include <string>
#include <type_traits>

namespace demo {

// C++20 concepts
template <typename T>
concept Callable = std::is_invocable_v<T>;

template <Callable T>
void Run(const std::string& name, T demo) {
  std::cout << std::endl << " --- " << name << " --- " << std::endl;
  demo();
  std::cout << std::endl << " --- " << name << " exit scope --- " << std::endl;
}

}  // namespace demo

#endif  // META_COMMON_DEMO_WRAPPER_H_
