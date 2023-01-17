#include <iostream>
#include <map>
#include <set>
#include <string>

#include "meta/common/demo_wrapper.h"
#include "meta/common/print_containers.h"

void SetDemo() {
  demo::EnterScope("SetDemo");

  std::set<std::string> student_set;
  student_set.emplace("John");
  student_set.emplace("Jane");
  student_set.emplace("Jack");
  student_set.emplace("Jill");
  student_set.emplace("Jenny");
  std::cout << "set does not reserve insertion order" << std::endl;
  meta::common::Print("student_set", student_set);

  demo::ExitScope("SetDemo");
}

void MapDemo() {
  demo::EnterScope("MapDemo");

  std::map<std::string, int> ordered_payroll;
  ordered_payroll.emplace("John", 1000);
  ordered_payroll.emplace("Jane", 2000);
  ordered_payroll.emplace("Jack", 3000);
  ordered_payroll.emplace("Jill", 4000);
  ordered_payroll.emplace("Jenny", 5000);
  std::cout << "map reserves insertion order" << std::endl;
  meta::common::Print("ordered_payroll", ordered_payroll);

  demo::ExitScope("MapDemo");
}

int main(int argc, char const *argv[]) {
  SetDemo();
  MapDemo();
}
