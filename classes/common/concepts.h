#ifndef CLASSES_COMMON_CONCEPTS_H_
#define CLASSES_COMMON_CONCEPTS_H_

#include <memory>
#include <type_traits>

// ec for element container
namespace ec {

template <typename Container, class Element>
concept ElementContainer =
    std::is_same_v<typename Container::value_type, Element>;

template <typename Container, class Element>
concept ElementPtrContainer =
    std::is_same_v<typename Container::value_type, std::unique_ptr<Element>> ||
    std::is_same_v<typename Container::value_type, std::shared_ptr<Element>> ||
    std::is_same_v<typename Container::value_type, std::weak_ptr<Element>>;

}  // namespace ec

#endif  // CLASSES_COMMON_CONCEPTS_H_
