#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "meta/common/demo_wrapper.h"
#include "meta/common/print_containers.h"

void VectorDemo() {
  demo::EnterScope("VectorDemo");

  std::vector<std::string> payroll{"John", "Jane", "Jack", "Jill"};
  meta::common::Print("payroll", payroll);

  demo::ExitScope("VectorDemo");
}

void DequeDemo() {
  demo::EnterScope("DequeDemo");

  std::deque<std::string> names{"Alice", "Bob", "Charlie", "Dave"};
  meta::common::Print("names", names);

  demo::ExitScope("DequeDemo");
}

void ListDemo() {
  demo::EnterScope("ListDemo");

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

  demo::ExitScope("ListDemo");
}

void ForwardListDemo() {
  demo::EnterScope("ForwardListDemo");

  std::forward_list<std::string> names{"Alice", "Bob", "Charlie", "Dave"};
  meta::common::Print("names", names);

  demo::ExitScope("ForwardListDemo");
}

int main(int argc, char const* argv[]) {
  VectorDemo();
  DequeDemo();
  ListDemo();
  ForwardListDemo();
}
