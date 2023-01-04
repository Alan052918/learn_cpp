#ifndef COMMON_BOOK_H_
#define COMMON_BOOK_H_

#include <memory>
#include <string>
#include <vector>

#include "classes/common/person.h"

class Person;

class Book : public std::enable_shared_from_this<Book> {
 public:
  Book(const std::string &name,
       const std::vector<std::weak_ptr<Person>> &authors);

  Book(const std::string &name);

  Book(const Book &another) noexcept;

  Book(Book &&another) noexcept;

  ~Book();

  Book &operator=(const Book &another) noexcept;

  Book &operator=(Book &&another) noexcept;

  explicit operator bool() const noexcept;

  operator std::string() const noexcept;

  friend std::ostream &operator<<(std::ostream &out, const Book &book);

  const std::string AuthorsString() const;

  const std::string name() const;
  void name(const std::string &new_name);

  const std::vector<std::weak_ptr<Person>> authors() const;
  void authors(const std::vector<std::weak_ptr<Person>> &new_authors);
  void AddAuthor(const std::shared_ptr<Person> &new_author);
  void RemoveAuthor(const std::shared_ptr<Person> &rm_author);
  void ClearAuthors();

 private:
  std::string name_;
  std::vector<std::weak_ptr<Person>> authors_;
};

#endif  // COMMON_BOOK_H_
