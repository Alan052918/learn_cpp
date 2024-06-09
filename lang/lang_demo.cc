#include <iostream>
#include <string>

#include "meta/common/demo_wrapper.h"
#include "meta/common/print_containers.h"

enum UnscopedEnumExample { kFirst = 0, kSecond, kThird };
// // clang: Redefinition of enumerator kFirst
// // clang: Redefinition of enumerator kSecond
// enum UnscopedRedefinitionExample { kFirst = 0, kSecond, kThrid };

enum class ScopedEnumExample { kFirst = 0, kSecond, kThird };
enum class ScopedRedefinitionEnumExample { kFirst = 0, kSecond, kThird };

void EnumDemo() {
  demo::EnterScope("Enum Demo");

  demo::ExitScope("Enum Demo");
}

// Union: a special class that can only hold one of its non-static data members
// at a time
// - memory layout: as least as big as necessary to hold its largest data
// member, usually not larger. Each member is allocated as if it is the only
// member of the class
// - UB: reading from a member that is not the active member (most recently
// written)
union UnionExample {
  int32_t i;
  float f;
  uint8_t bytes[4];

  // if members are classes with user-defined constructors/destructors
  std::string str;
  std::vector<int> vec;
  ~UnionExample() {}
};

void UnionDemo() {
  demo::EnterScope("Union Demo");

  UnionExample u = {.i = 0x12345678};
  std::cout << std::hex << "u.i = 0x" << u.i << "\t u size: " << sizeof(u)
            << std::endl;

  u.f = 3.14;
  std::cout << std::dec << "u.f = " << u.f << "\t u size: " << sizeof(u)
            << std::endl;

  u.bytes[0] = 0x12;
  std::cout << "u.bytes[0] = 0x" << std::hex << u.bytes[0]
            << "\t u size: " << sizeof(u) << std::endl;

  u.str = "Hello";
  std::cout << "u.str = " << u.str << "\t u size: " << sizeof(u) << std::endl;
  u.str.~basic_string();

  new (&u.vec) std::vector<int>{1, 2, 3};
  meta::common::Print("u.vec", u.vec);
  std::cout << " u size: " << sizeof(u) << std::endl;
  u.vec.~vector();

  demo::ExitScope("Union Demo");
}

int main(int argc, char const *argv[]) {
  EnumDemo();
  UnionDemo();
}
