#include "templates/common/print_containers.h"

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

namespace templates::common {

// Sequential containers

template <typename T>
void Print(const std::vector<T> &container) {
  std::cout << "vector{ ";
  for (const auto &element : container) std::cout << element << " ";
  std::cout << "}" << std::endl;
}

template <typename T>
void Print(const std::deque<T> &container) {
  std::cout << "deque{ ";
  for (const auto &element : container) std::cout << element << " ";
  std::cout << "}" << std::endl;
}

template <typename T>
void Print(const std::list<T> &container) {
  std::cout << "list{ ";
  for (const auto &element : container) std::cout << element << " ";
  std::cout << "}" << std::endl;
}

template <typename T>
void Print(const std::forward_list<T> &container) {
  std::cout << "forward_list{ ";
  for (const auto &element : container) std::cout << element << " ";
  std::cout << "}" << std::endl;
}

// Associative containers

template <typename T>
void Print(const std::set<T> &container) {
  std::cout << "set{ ";
  for (const auto &element : container) std::cout << element << " ";
  std::cout << "}" << std::endl;
}

template <typename K, typename V>
void Print(const std::map<K, V> &container) {
  std::cout << "map{ ";
  for (const auto &element : container)
    std::cout << element.first << ":" << element.second << " ";
  std::cout << "}" << std::endl;
}

template <typename T>
void Print(const std::multiset<T> &container) {
  std::cout << "multiset{ ";
  for (const auto &element : container) std::cout << element << " ";
  std::cout << "}" << std::endl;
}

template <typename K, typename V>
void Print(const std::multimap<K, V> &container) {
  std::cout << "multimap{ ";
  for (const auto &element : container)
    std::cout << element.first << ":" << element.second << " ";
  std::cout << "}" << std::endl;
}

// Unordered associative containers

template <typename T>
void Print(const std::unordered_set<T> &container) {
  std::cout << "unordered_set{ ";
  for (const auto &element : container) std::cout << element << " ";
  std::cout << "}" << std::endl;
}

template <typename K, typename V>
void Print(const std::unordered_map<K, V> &container) {
  std::cout << "unordered_map{ ";
  for (const auto &element : container)
    std::cout << element.first << ":" << element.second << " ";
  std::cout << "}" << std::endl;
}

template <typename T>
void Print(const std::unordered_multiset<T> &container) {
  std::cout << "unordered_multiset{ ";
  for (const auto &element : container) std::cout << element << " ";
  std::cout << "}" << std::endl;
}

template <typename K, typename V>
void Print(const std::unordered_multimap<K, V> &container) {
  std::cout << "unordered_multimap{ ";
  for (const auto &element : container)
    std::cout << element.first << ":" << element.second << " ";
  std::cout << "}" << std::endl;
}

// Container adapters

template <typename T>
void Print(const std::stack<T> &container) {
  // TODO: Implement this function.
}

template <typename T>
void Print(const std::queue<T> &container) {
  // TODO: Implement this function.
}

template <typename T>
void Print(const std::priority_queue<T> &container) {
  // TODO: Implement this function.
}

}  // namespace templates::common

// Explicit instantiation
namespace templates::common {

// Sequential containers

template void Print<int>(const std::vector<int> &container);

template void Print<int>(const std::deque<int> &container);

template void Print<int>(const std::list<int> &container);

template void Print<int>(const std::forward_list<int> &container);

// Associative containers

template void Print<int>(const std::set<int> &container);

template void Print<int, int>(const std::map<int, int> &container);

template void Print<int>(const std::multiset<int> &container);

template void Print<int, int>(const std::multimap<int, int> &container);

// Unordered associative containers

template void Print<int>(const std::unordered_set<int> &container);

template void Print<int, int>(const std::unordered_map<int, int> &container);

template void Print<int>(const std::unordered_multiset<int> &container);

template void Print<int, int>(
    const std::unordered_multimap<int, int> &container);

// Container adapters

template void Print<int>(const std::stack<int> &container);

template void Print<int>(const std::queue<int> &container);

template void Print<int>(const std::priority_queue<int> &container);

}  // namespace templates::common
