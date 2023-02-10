#ifndef CLASSES_COMMON_STUDENT_H_
#define CLASSES_COMMON_STUDENT_H_

#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

#include "classes/common/book.h"
#include "classes/common/concepts.h"

class Student : public Person {
 public:
  Student(const std::string& name, const int age,
          const std::vector<std::weak_ptr<Book>>& publications,
          const std::vector<std::weak_ptr<Book>>& text_books);

  Student(const std::string& name, const int age);
  Student(const std::string& name, const int age,
          const std::vector<std::weak_ptr<Book>>& text_books);

  Student();

  Student(const Student& another) noexcept;

  Student(Student&& another) noexcept;

  // the `override` keyword ensures that
  // - the function is virtual
  // - its is overriding a virtual function from a base class
  // Even though destructors are not inherited, a destructor in a derived class
  // overrides a base class destructor declared virtual
  ~Student() override;

  Student& operator=(const Student& another) noexcept;

  Student& operator=(Student&& another) noexcept;

  explicit operator bool() const noexcept override;

  operator std::string() const noexcept override;

  const std::string PublicationsString() const override;

  const std::string TextBooksString() const;

  const std::vector<std::weak_ptr<Book>> text_books() const;
  void text_books(const std::vector<std::weak_ptr<Book>>& new_text_books);
  void AddTextBook(const std::shared_ptr<Book>& new_text_book);
  void RemoveTextBook(const std::shared_ptr<Book>& rm_text_book);
  void ClearTextBooks();

 private:
  std::vector<std::weak_ptr<Book>> text_books_;

 public:
  friend std::ostream& operator<<(std::ostream& os, const Student& student);

  template <classes::common::ElementContainer<Student> Container>
  friend std::ostream& operator<<(std::ostream& os, const Container& students) {
    os << "Students {" << std::endl;
    for (const auto& student : students) os << "  " << student << std::endl;
    os << "}" << std::endl;
    return os;
  }

  template <classes::common::ElementPtrContainer<Student> PtrContainer>
  friend std::ostream& operator<<(std::ostream& os,
                                  const PtrContainer& students) {
    os << "Students {" << std::endl;
    for (const auto& student : students) {
      std::cout << "  ";
      if constexpr (std::is_same_v<typename PtrContainer::value_type,
                                   std::unique_ptr<Student>>) {
        os << *student << std::endl;
      } else if constexpr (std::is_same_v<typename PtrContainer::value_type,
                                          std::shared_ptr<Student>>) {
        os << *student << std::endl;
      } else if constexpr (std::is_same_v<typename PtrContainer::value_type,
                                          std::weak_ptr<Student>>) {
        if (!student.expired()) os << *student.lock() << std::endl;
      }
    }
    os << "}" << std::endl;
    return os;
  }
};

#endif  // CLASSES_COMMON_STUDENT_H_
