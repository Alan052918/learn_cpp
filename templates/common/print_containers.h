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

namespace templates::common {

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

}  // namespace templates::common

#endif  // TEMPLATES_COMMON_PRINT_CONTAINERS_H_
