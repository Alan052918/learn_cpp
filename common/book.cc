#include "common/book.h"

#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "common/person.h"

Book::Book(const std::string &name,
           const std::vector<std::weak_ptr<Person>> &authors)
    : name_(name), authors_(authors) {
  std::cout << "[Book] constructor: creating " << name_ << std::endl;
}

Book::Book(const std::string &name) : Book(name, {}) {}

Book::Book(const Book &another) noexcept
    : name_(another.name()), authors_(another.authors()) {
  std::cout << "[Book] copy constructor: copying " << name_ << std::endl;
}

Book::Book(Book &&another) noexcept
    : name_(another.name()), authors_(another.authors()) {
  std::cout << "[Book] move constructor: moving " << name_ << std::endl;
}

Book::~Book() {
  std::cout << "[Book] destructor: deleting " << name_ << std::endl;
}

Book &Book::operator=(const Book &another) noexcept = default;

Book &Book::operator=(Book &&another) noexcept = default;

Book::operator std::string() const noexcept {
  return "Book {name='" + name_ + "' " + AuthorsString() + "}";
}

std::ostream &operator<<(std::ostream &out, const Book &book) {
  out << static_cast<std::string>(book);
  return out;
}

const std::string Book::AuthorsString() const {
  std::string authors_str{"authors={ "};
  for (const std::weak_ptr<Person> &weak_person : authors_) {
    if (auto person = weak_person.lock()) authors_str += person->name() + " ";
  }
  authors_str += "}";
  return authors_str;
}

const std::string Book::name() const { return name_; }

void Book::name(const std::string &new_name) { name_ = new_name; }

const std::vector<std::weak_ptr<Person>> Book::authors() const {
  return authors_;
}

void Book::authors(const std::vector<std::weak_ptr<Person>> &new_authors) {
  authors_ = new_authors;
}

void Book::AddAuthor(const std::shared_ptr<Person> &new_author) {
  if (std::find_if(authors_.begin(), authors_.end(),
                   [&new_author](const std::weak_ptr<Person> &weak_author) {
                     return weak_author.lock() == new_author;
                   }) == authors_.end()) {
    authors_.push_back(new_author);
    new_author->AddPublication(shared_from_this());
  }
}

void Book::RemoveAuthor(const std::shared_ptr<Person> &rm_author) {
  authors_.erase(
      std::remove_if(authors_.begin(), authors_.end(),
                     [&rm_author](const std::weak_ptr<Person> &weak_author) {
                       return weak_author.lock() == rm_author;
                     }),
      authors_.end());
  rm_author->RemovePublication(shared_from_this());
}

void Book::ClearAuthors() { authors_.clear(); }
