#include <iostream>
#include <iterator>
#include <vector>

#include "meta/common/demo_wrapper.h"
#include "meta/common/print_containers.h"

void RangeAccessDemo() {
  demo::EnterScope("RangeAccessDemo");

  std::vector<int> nums{1, 2, 3, 4, 5};
  meta::common::Print("nums", nums);

  std::cout << "nums.begin() value: " << *nums.begin() << std::endl;
  std::cout << "nums.end() value: " << *nums.end() << std::endl;

  std::vector<std::vector<int>::iterator> nums_iters{nums.begin(),
                                                     std::next(nums.begin())};
  std::cout << "value of iter of iter: " << **nums_iters.begin() << std::endl;

  demo::ExitScope("RangeAccessDemo");
}

void OperationsDemo() {
  demo::EnterScope("OperationsDemo");

  std::vector<int> nums{1, 2, 3, 4, 5};
  meta::common::Print("nums", nums);

  std::vector<int>::iterator nums_iter = nums.begin();
  std::cout << "nums.begin(): " << *nums_iter << std::endl;
  std::cout << "next element of nums.begin(): " << *std::next(nums_iter)
            << std::endl;

  demo::ExitScope("OperationsDemo");
}

int main(int argc, const char* argv[]) {
  RangeAccessDemo();
  OperationsDemo();
}
