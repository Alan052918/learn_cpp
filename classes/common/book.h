#ifndef COMMON_BOOK_H_
#define COMMON_BOOK_H_

#include <memory>
#include <string>
#include <type_traits>
#include <vector>

#include "classes/common/concepts.h"
#include "classes/common/person.h"

class Person;

class Book : public std::enable_shared_from_this<Book> {
 public:
  Book(const std::string& name,
       const std::vector<std::weak_ptr<Person>>& authors);

  Book(const std::string& name);

  Book(const Book& another) noexcept;

  Book(Book&& another) noexcept;

  ~Book();

  Book& operator=(const Book& another) noexcept;

  Book& operator=(Book&& another) noexcept;

  explicit operator bool() const noexcept;

  operator std::string() const noexcept;

  const std::string AuthorsString() const;

  const std::string name() const;
  void name(const std::string& new_name);

  const std::vector<std::weak_ptr<Person>> authors() const;
  void authors(const std::vector<std::weak_ptr<Person>>& new_authors);
  void AddAuthor(const std::shared_ptr<Person>& new_author);
  void RemoveAuthor(const std::shared_ptr<Person>& rm_author);
  void ClearAuthors();

 private:
  std::string name_;
  std::vector<std::weak_ptr<Person>> authors_;

 public:
  friend std::ostream& operator<<(std::ostream& os, const Book& book);

  template <ec::ElementContainer<Book> Container>
  friend std::ostream& operator<<(std::ostream& os, const Container& books) {
    os << "Books {" << std::endl;
    for (const auto& book : books) std::cout << "  " << book << std::endl;
    os << "}" << std::endl;
    return os;
  }

  template <ec::ElementPtrContainer<Book> PtrContainer>
  friend std::ostream& operator<<(std::ostream& os, const PtrContainer& books) {
    os << "Books {" << std::endl;
    for (const auto& book : books) {
      std::cout << "  ";
      if constexpr (std::is_same_v<typename PtrContainer::value_type,
                                   std::unique_ptr<Book>>) {
        os << *book << std::endl;
      } else if constexpr (std::is_same_v<typename PtrContainer::value_type,
                                          std::shared_ptr<Book>>) {
        os << *book << std::endl;
      } else if constexpr (std::is_same_v<typename PtrContainer::value_type,
                                          std::weak_ptr<Book>>) {
        if (!book.expired()) os << *book.lock() << std::endl;
      }
    }
    os << "}" << std::endl;
    return os;
  }
};

#endif  // COMMON_BOOK_H_
