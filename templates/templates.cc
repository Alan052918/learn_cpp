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
#include "classes/common/student.h"
#include "templates/common/print_containers.h"

int main() {
  std::vector<Person> people;

  Person alice("Alice");
  people.push_back(alice);

  people.emplace_back("Bob");
  people.emplace_back("Charlie");
  people.emplace_back("Dave");

  // std::vector<std::string> vec{"one", "two", "three"};
  // templates::common::Print(vec);

  std::list<int> list{1, 2, 3};
  templates::common::Print(list);
}
