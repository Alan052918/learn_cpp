#ifndef TEMPLATES_COMMON_PRINT_CONTAINERS_H_
#define TEMPLATES_COMMON_PRINT_CONTAINERS_H_

#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "classes/common/person.h"

// For C++ templates, including the definitions in header is the only way to
// compile, since the compiler needs to know the full definition of the
// templates in order to instantiate.
// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

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
  std::cerr << "void Print(const std::stack<T> &container) Not implemented yet"
            << std::endl;
}

template <typename T>
void Print(const std::queue<T> &container) {
  // TODO: Implement this function.
  std::cerr << "void Print(const std::queue<T> &container) Not implemented yet"
            << std::endl;
}

template <typename T>
void Print(const std::priority_queue<T> &container) {
  // TODO: Implement this function.
  std::cerr << "void Print(const std::priority_queue<T> &container) Not "
               "implemented yet"
            << std::endl;
}

}  // namespace templates::common

#endif  // TEMPLATES_COMMON_PRINT_CONTAINERS_H_
