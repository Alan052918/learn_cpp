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

#include "meta/common/print_containers.h"

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
Print(const std::string_view name, const Container &container) {
  std::cout << name << " { ";
  for (const auto &element : container) {
    if constexpr (std::is_same_v<typename Container::value_type,
                                 std::weak_ptr<Person>>) {
      if (!element.expired()) std::cout << *element.lock() << " ";
    } else {
      std::cout << element << " ";
    }
  }
  std::cout << "}" << std::endl;
}

// map, multimap, unordered_map, unordered_multimap

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
Print(const std::string_view name, const Container &container) {
  std::cout << name << " {" << std::endl;
  for (const auto &element : container)
    std::cout << "  " << element.first << ": " << element.second << std::endl;
  std::cout << "}" << std::endl;
}

}  // namespace meta::common

namespace meta::common {

// vector, deque, list, forward_list

template void Print(const std::string_view name,
                    const std::vector<int> &container);
template void Print(const std::string_view name,
                    const std::deque<int> &container);
template void Print(const std::string_view name,
                    const std::list<int> &container);
template void Print(const std::string_view name,
                    const std::forward_list<int> &container);

template void Print(const std::string_view name,
                    const std::vector<double> &container);
template void Print(const std::string_view name,
                    const std::deque<double> &container);
template void Print(const std::string_view name,
                    const std::list<double> &container);
template void Print(const std::string_view name,
                    const std::forward_list<double> &container);

template void Print(const std::string_view name,
                    const std::vector<std::string> &container);
template void Print(const std::string_view name,
                    const std::deque<std::string> &container);
template void Print(const std::string_view name,
                    const std::list<std::string> &container);
template void Print(const std::string_view name,
                    const std::forward_list<std::string> &container);

template void Print(const std::string_view name,
                    const std::vector<std::weak_ptr<Person>> &container);
template void Print(const std::string_view name,
                    const std::deque<std::weak_ptr<Person>> &container);
template void Print(const std::string_view name,
                    const std::list<std::weak_ptr<Person>> &container);
template void Print(const std::string_view name,
                    const std::forward_list<std::weak_ptr<Person>> &container);

// set, multiset, unordered_set, unordered_multiset

template void Print(const std::string_view name,
                    const std::set<int> &container);
template void Print(const std::string_view name,
                    const std::multiset<int> &container);
template void Print(const std::string_view name,
                    const std::unordered_set<int> &container);
template void Print(const std::string_view name,
                    const std::unordered_multiset<int> &container);

template void Print(const std::string_view name,
                    const std::set<double> &container);
template void Print(const std::string_view name,
                    const std::multiset<double> &container);
template void Print(const std::string_view name,
                    const std::unordered_set<double> &container);
template void Print(const std::string_view name,
                    const std::unordered_multiset<double> &container);

template void Print(const std::string_view name,
                    const std::set<std::string> &container);
template void Print(const std::string_view name,
                    const std::multiset<std::string> &container);
template void Print(const std::string_view name,
                    const std::unordered_set<std::string> &container);
template void Print(const std::string_view name,
                    const std::unordered_multiset<std::string> &container);

// template void Print(const std::string_view name,
//                     const std::set<std::weak_ptr<Person>> &container);
// template void Print(const std::string_view name,
//                     const std::multiset<std::weak_ptr<Person>> &container);
// template void Print(const std::string_view name,
//                     const std::unordered_set<std::weak_ptr<Person>>
//                     &container);
// template void Print(
//     const std::string_view name,
//     const std::unordered_multiset<std::weak_ptr<Person>> &container);

// map, multimap, unordered_map, unordered_multimap

template void Print(const std::string_view name,
                    const std::map<int, int> &container);
template void Print(const std::string_view name,
                    const std::multimap<int, int> &container);
template void Print(const std::string_view name,
                    const std::unordered_map<int, int> &container);
template void Print(const std::string_view name,
                    const std::unordered_multimap<int, int> &container);

template void Print(const std::string_view name,
                    const std::map<double, int> &container);
template void Print(const std::string_view name,
                    const std::multimap<double, int> &container);
template void Print(const std::string_view name,
                    const std::unordered_map<double, int> &container);
template void Print(const std::string_view name,
                    const std::unordered_multimap<double, int> &container);

template void Print(const std::string_view name,
                    const std::map<std::string, int> &container);
template void Print(const std::string_view name,
                    const std::multimap<std::string, int> &container);
template void Print(const std::string_view name,
                    const std::unordered_map<std::string, int> &container);
template void Print(const std::string_view name,
                    const std::unordered_multimap<std::string, int> &container);

// template void Print(const std::string_view name,
//                     const std::map<std::weak_ptr<Person>, int> &container);
// template void Print(const std::string_view name,
//                     const std::multimap<std::weak_ptr<Person>, int>
//                     &container);
// template void Print(
//     const std::string_view name,
//     const std::unordered_map<std::weak_ptr<Person>, int> &container);
// template void Print(
//     const std::string_view name,
//     const std::unordered_multimap<std::weak_ptr<Person>, int> &container);

}  // namespace meta::common
