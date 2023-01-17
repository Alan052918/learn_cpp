#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "classes/common/person.h"
#include "meta/common/demo_wrapper.h"
#include "meta/common/print_containers.h"

void TemplateFunctionsDemo() {
  demo::EnterScope("TemplateFunctionsDemo");

  std::vector<std::weak_ptr<Person>> people_vec;

  Person alice{"Alice"};
  std::cout << "alice: " << alice << std::endl << std::endl;

  auto shared_alice = std::make_shared<Person>(alice);
  std::cout << "shared_alice: " << *shared_alice << std::endl << std::endl;

  people_vec.push_back(shared_alice);
  std::cout << "back of people: " << *people_vec.back().lock() << std::endl
            << std::endl;

  auto shared_bob = std::make_shared<Person>("Bob");
  people_vec.push_back(shared_bob);
  std::cout << "back of people: " << *people_vec.back().lock() << std::endl
            << std::endl;

  // std::cout << people_vec << std::endl;  // Outputs "People: Alice Bob Eve "
  meta::common::Print("people_vec", people_vec);

  std::vector<std::string> vec{"one", "two", "three"};
  meta::common::Print("vec", vec);

  std::list<int> list{1, 2, 3};
  meta::common::Print("list", list);

  demo::ExitScope("TemplateFunctionsDemo");
}

int main() { TemplateFunctionsDemo(); }
