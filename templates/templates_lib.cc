#include "templates_lib.h"

#include <iostream>

Foo::Foo(int val) : val_(val) {}

const int Foo::val() const { return val_; }

void Foo::val(const int val) { val_ = val; }

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

///////////////////////////////////////////////////////////////////////////////
// Explicit instantiation declarations
// - prevents implicit instantiations of the template

// Sequential containers

template void Print(const std::vector<int> &container);
template void Print(const std::deque<int> &container);
template void Print(const std::list<int> &container);
template void Print(const std::forward_list<int> &container);

template void Print(const std::vector<double> &container);
template void Print(const std::deque<double> &container);
template void Print(const std::list<double> &container);
template void Print(const std::forward_list<double> &container);

template void Print(const std::vector<std::string> &container);
template void Print(const std::deque<std::string> &container);
template void Print(const std::list<std::string> &container);
template void Print(const std::forward_list<std::string> &container);

template void Print(const std::vector<Person> &container);
template void Print(const std::deque<Person> &container);
template void Print(const std::list<Person> &container);
template void Print(const std::forward_list<Person> &container);

// Associative containers

template void Print(const std::set<int> &container);
template void Print(const std::map<int, int> &container);
template void Print(const std::multiset<int> &container);
template void Print(const std::multimap<int, int> &container);

template void Print(const std::set<double> &container);
template void Print(const std::map<double, int> &container);
template void Print(const std::multiset<double> &container);
template void Print(const std::multimap<double, int> &container);

template void Print(const std::set<std::string> &container);
template void Print(const std::map<std::string, int> &container);
template void Print(const std::multiset<std::string> &container);
template void Print(const std::multimap<std::string, int> &container);

// Unordered associative containers

template void Print(const std::unordered_set<int> &container);
template void Print(const std::unordered_map<int, int> &container);
template void Print(const std::unordered_multiset<int> &container);
template void Print(const std::unordered_multimap<int, int> &container);

template void Print(const std::unordered_set<double> &container);
template void Print(const std::unordered_map<double, int> &container);
template void Print(const std::unordered_multiset<double> &container);
template void Print(const std::unordered_multimap<double, int> &container);

template void Print(const std::unordered_set<std::string> &container);
template void Print(const std::unordered_map<std::string, int> &container);
template void Print(const std::unordered_multiset<std::string> &container);
template void Print(const std::unordered_multimap<std::string, int> &container);

// Container adapters

template void Print(const std::stack<int> &container);
template void Print(const std::queue<int> &container);
template void Print(const std::priority_queue<int> &container);

template void Print(const std::stack<double> &container);
template void Print(const std::queue<double> &container);
template void Print(const std::priority_queue<double> &container);

template void Print(const std::stack<std::string> &container);
template void Print(const std::queue<std::string> &container);
template void Print(const std::priority_queue<std::string> &container);

///////////////////////////////////////////////////////////////////////////////
