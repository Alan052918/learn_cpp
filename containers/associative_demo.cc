#include <iostream>
#include <map>
#include <set>
#include <string>

// #include "templates/common/print_containers.h"
#include "meta/common/print_containers.h"

int main(int argc, char const *argv[]) {
  std::map<std::string, int> ordered_payroll;
  ordered_payroll.emplace("John", 1000);
  ordered_payroll.emplace("Jane", 2000);
  ordered_payroll.emplace("Jack", 3000);
  ordered_payroll.emplace("Jill", 4000);
  ordered_payroll.emplace("Jenny", 5000);
  std::cout << std::endl << "map reserves insertion order" << std::endl;
  // templates::common::Print(ordered_payroll);
  meta::common::Print("ordered_payroll", ordered_payroll);
}
