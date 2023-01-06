#ifndef META_COMMON_PRINT_CONTAINERS_H_
#define META_COMMON_PRINT_CONTAINERS_H_

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

#include "classes/common/person.h"

namespace meta::common {

// vector, deque, list, forward_list
// set, multiset, unordered_set, unordered_multiset

template <typename Container>
std::enable_if_t<
    std::is_same_v<Container, std::vector<typename Container::value_type>> ||
    std::is_same_v<Container, std::deque<typename Container::value_type>> ||
    std::is_same_v<Container, std::list<typename Container::value_type>> ||
    std::is_same_v<Container,
                   std::forward_list<typename Container::value_type>> ||
    std::is_same_v<Container, std::set<typename Container::value_type>> ||
    std::is_same_v<Container, std::multiset<typename Container::value_type>> ||
    std::is_same_v<Container,
                   std::unordered_set<typename Container::value_type>> ||
    std::is_same_v<Container,
                   std::unordered_multiset<typename Container::value_type>>>
Print(const std::string_view name, const Container &container);

// map, multimap, unordered_map, and unordered_multimap

template <typename Container>
std::enable_if_t<
    std::is_same_v<Container, std::map<typename Container::key_type,
                                       typename Container::mapped_type>> ||
    std::is_same_v<Container, std::multimap<typename Container::key_type,
                                            typename Container::mapped_type>> ||
    std::is_same_v<Container,
                   std::unordered_map<typename Container::key_type,
                                      typename Container::mapped_type>> ||
    std::is_same_v<Container,
                   std::unordered_multimap<typename Container::key_type,
                                           typename Container::mapped_type>>>
Print(const std::string_view name, const Container &container);

}  // namespace meta::common

namespace meta::common {

// vector, deque, list, forward_list

extern template void Print(const std::string_view name,
                           const std::vector<int> &container);
extern template void Print(const std::string_view name,
                           const std::deque<int> &container);
extern template void Print(const std::string_view name,
                           const std::list<int> &container);
extern template void Print(const std::string_view name,
                           const std::forward_list<int> &container);

extern template void Print(const std::string_view name,
                           const std::vector<double> &container);
extern template void Print(const std::string_view name,
                           const std::deque<double> &container);
extern template void Print(const std::string_view name,
                           const std::list<double> &container);
extern template void Print(const std::string_view name,
                           const std::forward_list<double> &container);

extern template void Print(const std::string_view name,
                           const std::vector<std::string> &container);
extern template void Print(const std::string_view name,
                           const std::deque<std::string> &container);
extern template void Print(const std::string_view name,
                           const std::list<std::string> &container);
extern template void Print(const std::string_view name,
                           const std::forward_list<std::string> &container);

extern template void Print(const std::string_view name,
                           const std::vector<std::weak_ptr<Person>> &container);
extern template void Print(const std::string_view name,
                           const std::deque<std::weak_ptr<Person>> &container);
extern template void Print(const std::string_view name,
                           const std::list<std::weak_ptr<Person>> &container);
extern template void Print(
    const std::string_view name,
    const std::forward_list<std::weak_ptr<Person>> &container);

// set, multiset, unordered_set, unordered_multiset

extern template void Print(const std::string_view name,
                           const std::set<int> &container);
extern template void Print(const std::string_view name,
                           const std::multiset<int> &container);
extern template void Print(const std::string_view name,
                           const std::unordered_set<int> &container);
extern template void Print(const std::string_view name,
                           const std::unordered_multiset<int> &container);

extern template void Print(const std::string_view name,
                           const std::set<double> &container);
extern template void Print(const std::string_view name,
                           const std::multiset<double> &container);
extern template void Print(const std::string_view name,
                           const std::unordered_set<double> &container);
extern template void Print(const std::string_view name,
                           const std::unordered_multiset<double> &container);

extern template void Print(const std::string_view name,
                           const std::set<std::string> &container);
extern template void Print(const std::string_view name,
                           const std::multiset<std::string> &container);
extern template void Print(const std::string_view name,
                           const std::unordered_set<std::string> &container);
extern template void Print(
    const std::string_view name,
    const std::unordered_multiset<std::string> &container);

// extern template void Print(const std::string_view name,
//                            const std::set<std::weak_ptr<Person>> &container);
// extern template void Print(
//     const std::string_view name,
//     const std::multiset<std::weak_ptr<Person>> &container);
// extern template void Print(
//     const std::string_view name,
//     const std::unordered_set<std::weak_ptr<Person>> &container);
// extern template void Print(
//     const std::string_view name,
//     const std::unordered_multiset<std::weak_ptr<Person>> &container);

// map, multimap, unordered_map, unordered_multimap

extern template void Print(const std::string_view name,
                           const std::map<int, int> &container);
extern template void Print(const std::string_view name,
                           const std::multimap<int, int> &container);
extern template void Print(const std::string_view name,
                           const std::unordered_map<int, int> &container);
extern template void Print(const std::string_view name,
                           const std::unordered_multimap<int, int> &container);

extern template void Print(const std::string_view name,
                           const std::map<double, int> &container);
extern template void Print(const std::string_view name,
                           const std::multimap<double, int> &container);
extern template void Print(const std::string_view name,
                           const std::unordered_map<double, int> &container);
extern template void Print(
    const std::string_view name,
    const std::unordered_multimap<double, int> &container);

extern template void Print(const std::string_view name,
                           const std::map<std::string, int> &container);
extern template void Print(const std::string_view name,
                           const std::multimap<std::string, int> &container);
extern template void Print(
    const std::string_view name,
    const std::unordered_map<std::string, int> &container);
extern template void Print(
    const std::string_view name,
    const std::unordered_multimap<std::string, int> &container);

// extern template void Print(
//     const std::string_view name,
//     const std::map<std::weak_ptr<Person>, int> &container);
// extern template void Print(
//     const std::string_view name,
//     const std::multimap<std::weak_ptr<Person>, int> &container);
// extern template void Print(
//     const std::string_view name,
//     const std::unordered_map<std::weak_ptr<Person>, int> &container);
// extern template void Print(
//     const std::string_view name,
//     const std::unordered_multimap<std::weak_ptr<Person>, int> &container);

}  // namespace meta::common

#endif  // META_COMMON_PRINT_CONTAINERS_H_
