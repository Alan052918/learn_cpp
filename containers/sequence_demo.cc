#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// #include "templates/common/print_containers.h"
#include "meta/common/print_containers.h"

void VectorDemo() {
  std::cout << std::endl << " --- VectorDemo --- " << std::endl;

  std::vector<std::string> payroll{"John", "Jane", "Jack", "Jill"};
  meta::common::Print("payroll", payroll);

  std::cout << std::endl << " --- VectorDemo exit scope --- " << std::endl;
}

void DequeDemo() {
  std::cout << std::endl << " --- DequeDemo --- " << std::endl;

  std::deque<std::string> names{"Alice", "Bob", "Charlie", "Dave"};
  meta::common::Print("names", names);

  std::cout << std::endl << " --- DequeDemo exit scope --- " << std::endl;
}

void ListDemo() {
  std::cout << std::endl << " --- ListDemo --- " << std::endl;

  std::list<std::string> names{"Alice", "Bob", "Charlie", "Dave"};
  meta::common::Print("names", names);

  names.push_back("Eve");
  meta::common::Print("names", names);

  // transfer element i from c to *this before p
  names.splice(names.end(), names, names.begin());
  meta::common::Print("names", names);

  // transfer elements in range [f, l) from c to *this before p
  names.splice(names.end(), names, names.begin(), std::next(names.begin(), 2));
  meta::common::Print("names", names);

  std::cout << std::endl << " --- ListDemo exit scope --- " << std::endl;
}

void ForwardListDemo() {
  std::cout << std::endl << " --- ForwardListDemo --- " << std::endl;

  std::forward_list<std::string> names{"Alice", "Bob", "Charlie", "Dave"};
  meta::common::Print("names", names);

  std::cout << std::endl << " --- ForwardListDemo exit scope --- " << std::endl;
}

int main(int argc, char const* argv[]) {
  VectorDemo();
  DequeDemo();
  ListDemo();
  ForwardListDemo();
}
