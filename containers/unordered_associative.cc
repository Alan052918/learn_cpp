#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "templates/common/print_containers.h"

void loopErase() {
  std::cout << std::endl << "loopErase demo" << std::endl;

  std::cout << "initial: ";
  std::unordered_set<int> num_set({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  templates::common::Print(num_set);
  for (auto iter = num_set.begin(); iter != num_set.end();) {
    iter = (*iter & 1) == 1 ? num_set.erase(iter) : std::next(iter);
  }
  std::cout << "after erasing odd numbers: ";
  templates::common::Print(num_set);
}

int main() {
  std::unordered_map<std::string, int> payroll;
  payroll.insert(std::make_pair("adam", 11000));
  payroll.insert({"alan", 10000});
  payroll.emplace("bob", 9000);
  std::cout << "existent key's value" << payroll.at("alan") << std::endl;
  std::cout << "non-existent key's value: " << payroll["cat"] << std::endl;

  // emplace and insert returns a pair<unordered_map::iterator, bool>
  // first one is an iterator tothe inserted element
  // second one is true if insertion took place, false if no insertion
  const auto& ret = payroll.emplace("dean", 4000);
  std::cout << "Insert {" << ret.first->first << ", " << ret.first->second
            << "} " << ret.second << std::endl;

  // find returns an iterator to the element with key
  // or pass-the-end iterator .end() if no element with this key exists
  const auto element = payroll.find("calvin");
  if (element != payroll.end()) {
    std::cout << "Found " << element->first << " " << element->second
              << std::endl;
  } else {
    std::cout << "Not found" << std::endl;
  }

  std::cout << std::endl
            << "unordered map mess with insertion order" << std::endl;
  templates::common::Print(payroll);

  loopErase();
}
