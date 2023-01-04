#ifndef OOP_STUDENT_H_
#define OOP_STUDENT_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "lib/book.h"
#include "lib/person.h"

class Student : public Person {
 public:
  Student(const std::string &name, const int age,
          const std::vector<std::weak_ptr<Book>> &publications,
          const std::vector<std::weak_ptr<Book>> &text_books);

  Student(const std::string &name, const int age);
  Student(const std::string &name, const int age,
          const std::vector<std::weak_ptr<Book>> &text_books);

  Student();

  Student(const Student &another) noexcept;

  Student(Student &&another) noexcept;

  // the `override` keyword ensures that
  // - the function is virtual
  // - its is overriding a virtual function from a base class
  // Even though destructors are not inherited, a destructor in a derived class
  // overrides a base class destructor declared virtual
  ~Student() override;

  Student &operator=(const Student &another) noexcept;

  Student &operator=(Student &&another) noexcept;

  explicit operator bool() const noexcept override;

  operator std::string() const noexcept override;

  friend std::ostream &operator<<(std::ostream &out, const Student &student);

  template <typename Container>
  friend std::ostream &operator<<(std::ostream &out,
                                  const Container &container);

  const std::string PublicationsString() const override;

  const std::string TextBooksString() const;

  const std::vector<std::weak_ptr<Book>> text_books() const;
  void text_books(const std::vector<std::weak_ptr<Book>> &new_text_books);
  void AddTextBook(const std::shared_ptr<Book> &new_text_book);
  void RemoveTextBook(const std::shared_ptr<Book> &rm_text_book);
  void ClearTextBooks();

 private:
  std::vector<std::weak_ptr<Book>> text_books_;
};

#endif  // OOP_STUDENT_H_
