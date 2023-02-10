#ifndef META_COMMON_PRINT_CONTAINERS_H_
#define META_COMMON_PRINT_CONTAINERS_H_

#include <algorithm>
#include <concepts>
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
concept IsSequenceOrAssociativeContainer =
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
                   std::unordered_multiset<typename Container::value_type>>;

// map, multimap, unordered_map, unordered_multimap
template <typename Container>
concept IsUnorderedAssociativeContainer =
    std::is_same_v<Container, std::map<typename Container::key_type,
                                       typename Container::mapped_type>> ||
    std::is_same_v<Container, std::multimap<typename Container::key_type,
                                            typename Container::mapped_type>> ||
    std::is_same_v<Container,
                   std::unordered_map<typename Container::key_type,
                                      typename Container::mapped_type>> ||
    std::is_same_v<Container,
                   std::unordered_multimap<typename Container::key_type,
                                           typename Container::mapped_type>>;

template <typename Container>
std::enable_if_t<IsSequenceOrAssociativeContainer<Container>> Print(
    const std::string_view name, const Container &container) {
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

template <typename Container>
std::enable_if_t<IsUnorderedAssociativeContainer<Container>> Print(
    const std::string_view name, const Container &container) {
  std::cout << name << " {" << std::endl;
  for (const auto &element : container)
    std::cout << "  " << element.first << ": " << element.second << std::endl;
  std::cout << "}" << std::endl;
}

}  // namespace meta::common

#endif  // META_COMMON_PRINT_CONTAINERS_H_
