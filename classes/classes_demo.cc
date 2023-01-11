#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "classes/common/book.h"
#include "classes/common/file_handle.h"
#include "classes/common/person.h"
#include "classes/common/student.h"

void ConstructorsDemo() {
  std::cout << std::endl << " --- ConstructorDemo --- " << std::endl;

  std::vector<std::unique_ptr<Person>> people;
  people.reserve(3);

  // calling complete constructor
  Student alice("Alice", 24, {}, {});
  std::cout << alice << std::endl << std::endl;

  Book war_and_peace("War and Peace");
  std::cout << war_and_peace << std::endl << std::endl;

  people.push_back(std::make_unique<Student>(alice));
  std::cout << people << std::endl;

  // calling delegating constructors
  Student bob("Bob", 25);
  std::cout << bob << std::endl << std::endl;

  Student charlie("Charlie", 26, {});
  std::cout << charlie << std::endl << std::endl;

  people.push_back(std::make_unique<Student>(bob));
  people.push_back(std::make_unique<Student>(charlie));
  std::cout << people << std::endl;

  // calling default constructor
  Student anonymous;
  std::cout << anonymous << std::boolalpha
            << (anonymous ? " is not null" : " is null") << std::endl;
  people.push_back(std::make_unique<Student>(anonymous));
  std::cout << people << std::endl;

  // calling copy constructor
  Student another_alice(alice);
  std::cout << "copied alice: " << another_alice << std::endl;
  std::cout << "original alice: " << alice << std::endl << std::endl;

  // calling move constructor
  Student moved_bob(std::move(bob));
  std::cout << "moved bob: " << moved_bob << std::endl;
  std::cout << "original bob: " << bob << std::endl;

  std::cout << std::endl << " --- ConstructorDemo exit scope --- " << std::endl;
}

void RAIIDemo() {
  std::cout << std::endl << " --- RAIIDemo --- " << std::endl;

  try {
    std::cout << "enter scope" << std::endl;

    FileHandle file_handle("myfile.txt");

    file_handle.Append("Hello, World!");
    std::cout << file_handle << std::endl;

    file_handle.Append("It's Junda.");
    std::cout << file_handle << std::endl;

    std::cout << "exit scope" << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << " --- RAIIDemo exit scope --- " << std::endl;
}

// ----------------------------------------------------------------------------
// VTable monkey patching example: (https://gist.github.com/netguy204/6097063)
// Doesn't work on macOS Ventura 13.1: vtable is in `__DATA_CONST` section of
// virtual memory (https://developer.apple.com/forums/thread/678123)
class Foo {
 public:
  virtual void Bar() { std::cout << "Bar" << std::endl; }
};

void DynamicOverride(Foo* foo) { std::cout << "Qux" << std::endl; }

void MonkeyPatchingDemo() {
  std::cout << std::endl << " --- MonkeyPatchingDemo --- " << std::endl;

  Foo* foo = new Foo();
  void** vtable = *(void***)foo;

  foo->Bar();

  std::cout << "mess with Foo's vtable..." << std::endl;
  void (Foo::*ptr)() = &Foo::Bar;
  void* offset = *(void**)&ptr;
  vtable[((uintptr_t)offset) / sizeof(void*)] = (void*)&DynamicOverride;
  std::cout << "done" << std::endl;

  foo->Bar();
  std::cout << "affects future instances as well" << std::endl;

  Foo* new_foo = new Foo();
  new_foo->Bar();

  std::cout << std::endl
            << " --- MonkeyPatchingDemo exit scope --- " << std::endl;
}
// ----------------------------------------------------------------------------

int main(int argc, char const* argv[]) {
  ConstructorsDemo();
  RAIIDemo();
  // MonkeyPatchingDemo();
}
