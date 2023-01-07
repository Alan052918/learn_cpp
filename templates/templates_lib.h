#ifndef TEMPLATES_TEMPLATES_LIB_H_
#define TEMPLATES_TEMPLATES_LIB_H_

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

class Foo {
 public:
  Foo(int val);

  // friend templates
  // https://isocpp.org/wiki/faq/templates#template-friends
  // just put the friend template function definition in the class already
  template <typename Container>
  friend std::ostream &operator<<(std::ostream &os, const Container &foos) {
    for (const auto &foo : foos) os << foo.val_ << " ";
    return os;
  }

  const int val() const;
  void val(const int val);

 private:
  int val_;
};

namespace templates {

// Sequential containers

template <typename T>
void Print(const std::vector<T> &container);

template <typename T>
void Print(const std::deque<T> &container);

template <typename T>
void Print(const std::list<T> &container);

template <typename T>
void Print(const std::forward_list<T> &container);

// Associative containers

template <typename T>
void Print(const std::set<T> &container);

template <typename K, typename V>
void Print(const std::map<K, V> &container);

template <typename T>
void Print(const std::multiset<T> &container);

template <typename K, typename V>
void Print(const std::multimap<K, V> &container);

// Unordered associative containers

template <typename T>
void Print(const std::unordered_set<T> &container);

template <typename K, typename V>
void Print(const std::unordered_map<K, V> &container);

template <typename T>
void Print(const std::unordered_multiset<T> &container);

template <typename K, typename V>
void Print(const std::unordered_multimap<K, V> &container);

// Container adapters

template <typename T>
void Print(const std::stack<T> &container);

template <typename T>
void Print(const std::queue<T> &container);

template <typename T>
void Print(const std::priority_queue<T> &container);

}  // namespace templates

namespace templates {

///////////////////////////////////////////////////////////////////////////////
// Template instantiation
// - a template itself is not an entity, no code is generated without
// instantiation of a template definition
// - template arguments must be determined at compile time for the compiler to
// generate actual functions

// Explicit instantiation declarations
// - prevents implicit instantiations of the template

// Sequential containers

extern template void Print(const std::vector<int> &container);
extern template void Print(const std::deque<int> &container);
extern template void Print(const std::list<int> &container);
extern template void Print(const std::forward_list<int> &container);

extern template void Print(const std::vector<double> &container);
extern template void Print(const std::deque<double> &container);
extern template void Print(const std::list<double> &container);
extern template void Print(const std::forward_list<double> &container);

extern template void Print(const std::vector<std::string> &container);
extern template void Print(const std::deque<std::string> &container);
extern template void Print(const std::list<std::string> &container);
extern template void Print(const std::forward_list<std::string> &container);

extern template void Print(const std::vector<Person> &container);
extern template void Print(const std::deque<Person> &container);
extern template void Print(const std::list<Person> &container);
extern template void Print(const std::forward_list<Person> &container);

// Associative containers

extern template void Print(const std::set<int> &container);
extern template void Print(const std::map<int, int> &container);
extern template void Print(const std::multiset<int> &container);
extern template void Print(const std::multimap<int, int> &container);

extern template void Print(const std::set<double> &container);
extern template void Print(const std::map<double, int> &container);
extern template void Print(const std::multiset<double> &container);
extern template void Print(const std::multimap<double, int> &container);

extern template void Print(const std::set<std::string> &container);
extern template void Print(const std::map<std::string, int> &container);
extern template void Print(const std::multiset<std::string> &container);
extern template void Print(const std::multimap<std::string, int> &container);

// Unordered associative containers

extern template void Print(const std::unordered_set<int> &container);
extern template void Print(const std::unordered_map<int, int> &container);
extern template void Print(const std::unordered_multiset<int> &container);
extern template void Print(const std::unordered_multimap<int, int> &container);

extern template void Print(const std::unordered_set<double> &container);
extern template void Print(const std::unordered_map<double, int> &container);
extern template void Print(const std::unordered_multiset<double> &container);
extern template void Print(
    const std::unordered_multimap<double, int> &container);

extern template void Print(const std::unordered_set<std::string> &container);
extern template void Print(
    const std::unordered_map<std::string, int> &container);
extern template void Print(
    const std::unordered_multiset<std::string> &container);
extern template void Print(
    const std::unordered_multimap<std::string, int> &container);

// Container adapters

extern template void Print(const std::stack<int> &container);
extern template void Print(const std::queue<int> &container);
extern template void Print(const std::priority_queue<int> &container);

extern template void Print(const std::stack<double> &container);
extern template void Print(const std::queue<double> &container);
extern template void Print(const std::priority_queue<double> &container);

extern template void Print(const std::stack<std::string> &container);
extern template void Print(const std::queue<std::string> &container);
extern template void Print(const std::priority_queue<std::string> &container);

///////////////////////////////////////////////////////////////////////////////

}  // namespace templates

#endif  // TEMPLATES_TEMPLATES_LIB_H_
