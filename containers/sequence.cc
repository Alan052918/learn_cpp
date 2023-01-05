#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "templates/common/print_containers.h"

int main(int argc, char const *argv[]) {
  std::vector<std::string> payroll{"John", "Jane", "Jack", "Jill"};
  templates::common::Print(payroll);
}
