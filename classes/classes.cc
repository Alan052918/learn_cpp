#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "common/book.h"
#include "common/person.h"
#include "common/student.h"

void PrintPeople(const std::vector<std::unique_ptr<Person>>& people) {
  std::cout << "People: [" << std::endl;
  std::for_each(people.begin(), people.end(), [](const auto& person) {
    std::cout << "  " << *person << std::endl;
  });
  std::cout << "]" << std::endl << std::endl;
}

void ConstructorsDemo() {
  std::cout << std::endl << " -- ConstructorDemo -- " << std::endl;

  std::vector<std::unique_ptr<Person>> people;
  people.reserve(3);

  // calling complete constructor
  Student alice("Alice", 24, {}, {});
  std::cout << alice << std::endl << std::endl;

  Book war_and_peace("War and Peace");
  std::cout << war_and_peace << std::endl << std::endl;

  people.push_back(std::make_unique<Student>(alice));
  PrintPeople(people);

  // calling delegating constructors
  Student bob("Bob", 25);
  std::cout << bob << std::endl << std::endl;

  Student charlie("Charlie", 26, {});
  std::cout << charlie << std::endl << std::endl;

  people.push_back(std::make_unique<Student>(bob));
  people.push_back(std::make_unique<Student>(charlie));
  PrintPeople(people);

  // calling default constructor
  Student anonymous;
  std::cout << anonymous << std::boolalpha
            << (anonymous ? " is not null" : " is null") << std::endl;
  people.push_back(std::make_unique<Student>(anonymous));
  PrintPeople(people);

  // calling copy constructor
  Student another_alice(alice);
  std::cout << "copied alice: " << another_alice << std::endl;
  std::cout << "original alice: " << alice << std::endl << std::endl;

  // calling move constructor
  Student moved_bob(std::move(bob));
  std::cout << "moved bob: " << moved_bob << std::endl;
  std::cout << "original bob: " << bob << std::endl << std::endl;

  std::cout << std::endl << " -- ConstructorDemo exit scope -- " << std::endl;
}

int main(int argc, char const* argv[]) { ConstructorsDemo(); }
