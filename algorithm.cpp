#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void PrintVec(std::vector<int>& nums) {
  for (const auto num : nums) std::cout << num << " ";
  std::cout << std::endl;
}

void lowerBound() {
  std::vector<int> numbers{1, 2, 3, 4, 5};
  std::cout << std::boolalpha;

  auto result = std::lower_bound(numbers.begin(), numbers.end(), 1);
  std::cout << *result << " " << (result == numbers.end()) << std::endl;

  result = std::lower_bound(numbers.begin(), numbers.end(), 3);
  std::cout << *result << " " << (result == numbers.end()) << std::endl;

  result = std::lower_bound(numbers.begin(), numbers.end(), 5);
  std::cout << *result << " " << (result == numbers.end()) << std::endl;

  result = std::lower_bound(numbers.begin(), numbers.end(), 10);
  std::cout << *result << " " << (result == numbers.end()) << std::endl;

  result = std::lower_bound(std::next(numbers.begin(), 1), numbers.end(),
                            10 - numbers.front());
  std::cout << *result << " " << (result == numbers.end()) << std::endl;

  numbers = {3, 24, 50, 79, 88, 150, 345};
  result = std::lower_bound(std::next(numbers.begin(), 1), numbers.end(),
                            200 - numbers.front());
  std::cout << *result << " " << (result == numbers.end()) << std::endl;
}

int main() {
  std::vector<int> nums{4, 5, 3, 6, 2, 5, 1};
  PrintVec(nums);

  // sort 1D vector in ascending order
  std::sort(nums.begin(), nums.end());
  PrintVec(nums);

  // sort 1D vector in descending order
  std::sort(nums.rbegin(), nums.rend());
  PrintVec(nums);

  std::string s("a quick brown fox jump over the bush");
  std::cout << s << std::endl;

  // erase-remove idom, remove whitespaces
  s.erase(std::remove_if(s.begin(), s.end(),
                         [](unsigned char c) { return std::isspace(c); }),
          s.end());

  // sort string in lexicographically ascending order
  std::sort(s.begin(), s.end());
  std::cout << s << std::endl;

  // sort string in lexicographically descending order
  std::sort(s.rbegin(), s.rend());
  std::cout << s << std::endl;

  // binary search
  lowerBound();
}
