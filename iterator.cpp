#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> nums{1, 2, 3};
  std::cout << *nums.begin() << std::endl;

  std::cout << std::distance(nums.begin(), nums.end()) << std::endl;

  auto itr = nums.begin();
  std::cout << *itr << std::endl;

  itr += 2;
  std::cout << *itr << std::endl;
  std::cout << std::boolalpha << (std::next(itr, 2) == nums.end()) << std::endl;
  itr += 1;
  std::cout << *itr << " " << std::boolalpha << (itr == nums.end())
            << std::endl;
}
