#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "meta/common/demo_wrapper.h"
#include "meta/common/print_containers.h"

std::vector<std::string> Tokenize(const std::string &s) {
  std::stringstream ss(s);
  std::vector<std::string> tokens;
  for (std::string token; std::getline(ss, token, ' ');)
    tokens.push_back(std::move(token));
  return tokens;
}

void SortDemo() {
  demo::EnterScope("SortDemo");

  std::vector<int> nums{4, 5, 3, 6, 2, 5, 1};
  meta::common::Print("nums", nums);

  // sort 1D vector in ascending order
  std::sort(nums.begin(), nums.end());
  meta::common::Print("nums", nums);

  // sort 1D vector in descending order
  std::sort(nums.rbegin(), nums.rend());
  meta::common::Print("nums", nums);

  std::string s = "a quick brown fox jump over the bush";
  std::cout << "original: '" << s << "'" << std::endl;

  std::vector<std::string> words = Tokenize(s);
  meta::common::Print("words", words);

  // sort a string in lexicographically ascending order
  std::sort(s.begin(), s.end());
  std::cout << "sorted asc: '" << s << "'" << std::endl;

  // sort a string in lexicographically descending order
  std::sort(s.rbegin(), s.rend());
  std::cout << "sorted desc: '" << s << "'" << std::endl;

  // sort words in lexicographically ascending order
  std::sort(words.begin(), words.end());
  std::cout << "sorted asc: ";
  meta::common::Print("words", words);

  // sort words in lexicographically descending order
  std::sort(words.rbegin(), words.rend());
  std::cout << "sorted desc: ";
  meta::common::Print("words", words);

  demo::ExitScope("SortDemo");
}

void LowerBoundDemo() {
  demo::EnterScope("LowerBoundDemo");

  std::vector<int> numbers{1, 2, 3, 4, 5};
  std::cout << std::boolalpha;
  meta::common::Print("numbers", numbers);

  auto result = std::lower_bound(numbers.begin(), numbers.end(), 1);
  std::cout << "lower bound 1: " << *result << " " << (result == numbers.end())
            << std::endl;

  result = std::lower_bound(numbers.begin(), numbers.end(), 3);
  std::cout << "lower bound 3: " << *result << " " << (result == numbers.end())
            << std::endl;

  result = std::lower_bound(numbers.begin(), numbers.end(), 5);
  std::cout << "lower bound 5: " << *result << " " << (result == numbers.end())
            << std::endl;

  result = std::lower_bound(numbers.begin(), numbers.end(), 10);
  std::cout << "lower bound 10: " << *result << " numbers.end()? "
            << (result == numbers.end()) << std::endl;

  result = std::lower_bound(std::next(numbers.begin(), 1), numbers.end(),
                            10 - numbers.front());
  std::cout << *result << " " << (result == numbers.end()) << std::endl;

  numbers = {3, 24, 50, 79, 88, 150, 345};
  result = std::lower_bound(std::next(numbers.begin(), 1), numbers.end(),
                            200 - numbers.front());
  std::cout << *result << " " << (result == numbers.end()) << std::endl;

  demo::ExitScope("LowerBoundDemo");
}

void BinarySearchDemo() {
  demo::EnterScope("BinarySearchDemo");

  LowerBoundDemo();

  demo::ExitScope("BinarySearchDemo");
}

int main() {
  SortDemo();
  BinarySearchDemo();
}
