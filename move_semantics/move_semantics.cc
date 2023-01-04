#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "lib/book.h"
#include "lib/person.h"
#include "lib/student.h"

int main(int argc, char const* argv[]) {
  std::vector<std::weak_ptr<Person>> people;
  people.reserve(3);

  Student alice("Alice", 24);
  std::cout << alice << std::endl;

  // vector.push_back calls the copy constructor of Student
  // passed in the named object `alice`
  people.push_back(std::make_shared<Student>(alice));

  std::cout << people << std::endl << std::endl;

  // vector.push_back calls the move constructor of Student
  // pass in the temporary Student object created by the delegating
  // constructor
  people.push_back(std::make_shared<Student>(Student("Bob", 25)));
  std::cout << people << std::endl << std::endl;

  Student charlie("Charlie", 26);
  std::cout << charlie << std::endl;

  // vector.push_back calls the move constructor of Student
  // pass in the named object `charlie` wrapped in std::move
  people.push_back(std::make_shared<Student>(std::move(charlie)));
  std::cout << people << std::endl << std::endl;
}
