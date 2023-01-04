#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

void printList(std::list<int>& list) {
  std::cout << "list{ ";
  std::for_each(list.begin(), list.end(),
                [](const int num) { std::cout << num << " "; });
  std::cout << "}" << std::endl;
}

typedef struct Result {
  int val;
  bool error;
} Result;

Result popMax(std::list<int>& list) {
  if (list.empty()) return {0, true};
  auto max = std::max_element(list.begin(), list.end());
  int max_val = *max;
  list.erase(max);
  return {max_val, false};
}

void popMaxDemo() {
  std::cout << "--- popMax demo ---" << std::endl;
  std::list<int> num_list = {1, 2, 3, 4};
  printList(num_list);

  Result result;
  do {
    result = popMax(num_list);
    std::cout << "max: " << result.val << " ";
    printList(num_list);
  } while (!result.error);
}

void mergeDemo() {
  std::cout << "--- merge demo ---" << std::endl;
  std::list<int> list1 = {5, 9, 1, 3, 3};
  std::list<int> list2 = {8, 7, 2, 3, 4, 4};

  list1.sort();
  list2.sort();
  std::cout << "list1: ";
  printList(list1);
  std::cout << "list2: ";
  printList(list2);

  list1.merge(list2);
  std::cout << "merged list1: ";
  printList(list1);
}

void spliceDemo() {
  std::cout << "--- splice demo ---" << std::endl;
  std::list<int> l = {5, 9, 1, 3, 3};
  printList(l);

  l.splice(l.begin(), l, std::prev(l.end()));
  printList(l);
}

void removeDemo() {
  std::cout << "--- remove demo ---" << std::endl;
  std::list<int> l = {5, 9, 1, 3, 3};
  printList(l);

  l.remove(3);
  printList(l);

  l.remove_if([](int val) { return val < 5; });
  printList(l);
}

void reverseDemo() {
  std::cout << "--- reverse demo ---" << std::endl;
  std::list<int> l = {5, 9, 1, 3, 3};
  printList(l);

  l.reverse();
  printList(l);
}

void sortDemo() {
  std::cout << "--- sort demo ---" << std::endl;
  std::list<int> l = {5, 9, 1, 3, 3};
  printList(l);

  l.sort();
  printList(l);
}

int main() {
  popMaxDemo();
  mergeDemo();
  spliceDemo();
  removeDemo();
  reverseDemo();
  sortDemo();
}
