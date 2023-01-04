#include "classes/common/student.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "classes/common/book.h"
#include "classes/common/person.h"

Student::Student(const std::string &name, const int age,
                 const std::vector<std::weak_ptr<Book>> &publications,
                 const std::vector<std::weak_ptr<Book>> &text_books)
    : Person(name, age, publications), text_books_(text_books) {
  std::cout << "[Student] constructor: creating " << name_ << std::endl;
}

Student::Student(const std::string &name, const int age)
    : Student(name, age, {}, {}) {}

Student::Student(const std::string &name, const int age,
                 const std::vector<std::weak_ptr<Book>> &text_books)
    : Student(name, age, {}, text_books) {}

Student::Student() : Person(), text_books_({}) {
  std::cout << "[Student] default constructor" << std::endl;
}

Student::Student(const Student &another) noexcept
    : Person(another), text_books_(another.text_books()) {
  std::cout << "[Student] copy constructor: copying " << name_ << std::endl;
}

Student::Student(Student &&another) noexcept
    : Person(std::move(another)), text_books_(another.text_books()) {
  std::cout << "[Student] move constructor: moving " << name_ << std::endl;
}

Student::~Student() {
  std::cout << "[Student] destructor: deleting " << name_ << std::endl;
}

Student &Student::operator=(const Student &another) noexcept = default;

Student &Student::operator=(Student &&another) noexcept = default;

Student::operator bool() const noexcept {
  // calling base class operator in derived class
  return Person::operator bool();
}

Student::operator std::string() const noexcept {
  return "Student {name='" + name_ + "' age=" + std::to_string(age_) + " " +
         PublicationsString() + " " + TextBooksString() + "}";
}

std::ostream &operator<<(std::ostream &os, const Student &student) {
  os << static_cast<std::string>(student);
  return os;
}

const std::string Student::PublicationsString() const {
  // `Person::` prefix: calling base class member functions in derived class
  // member functions
  return "student_" + Person::PublicationsString();
}

const std::string Student::TextBooksString() const {
  std::string text_books_str{"text_books={ "};
  for (const std::weak_ptr<Book> &weak_text_book : text_books_) {
    if (auto text_book = weak_text_book.lock())
      text_books_str += text_book->name() + " ";
  }
  text_books_str += "}";
  return text_books_str;
}

const std::vector<std::weak_ptr<Book>> Student::text_books() const {
  return text_books_;
}

void Student::text_books(
    const std::vector<std::weak_ptr<Book>> &new_text_books) {
  text_books_ = new_text_books;
}

void Student::AddTextBook(const std::shared_ptr<Book> &new_text_book) {
  // check if new_text_book is not already in text_books_
  if (std::find_if(text_books_.begin(), text_books_.end(),
                   [&new_text_book](const std::weak_ptr<Book> &weak_text_book) {
                     return weak_text_book.lock() == new_text_book;
                   }) == text_books_.end()) {
    text_books_.push_back(new_text_book);
    new_text_book->AddAuthor(shared_from_this());
  }
}

void Student::RemoveTextBook(const std::shared_ptr<Book> &rm_text_book) {
  text_books_.erase(
      std::remove_if(
          text_books_.begin(), text_books_.end(),
          [&rm_text_book](const std::weak_ptr<Book> &weak_text_book) {
            return weak_text_book.lock() == rm_text_book;
          }),
      text_books_.end());
  rm_text_book->RemoveAuthor(shared_from_this());
}

void Student::ClearTextBooks() { text_books_.clear(); }
