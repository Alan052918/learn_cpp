#include "classes/common/person.h"

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

#include "classes/common/book.h"

// complete constructor
Person::Person(const std::string& name, int age,
               const std::vector<std::weak_ptr<Book>>& publications)
    : name_(name), age_(age), publications_(publications) {
  std::cout << "[Person] constructor: creating " << name_ << std::endl;
}

// delegating constructors
Person::Person(const std::string& name) : Person(name, 0, {}) {}

Person::Person(const std::string& name, const int age)
    : Person(name, age, {}) {}

// 1. default constructor
Person::Person() : name_("<Anonymous>"), age_(0), publications_({}) {
  std::cout << "[Person] default constructor" << std::endl;
}

// 2. copy constructor
Person::Person(const Person& another) noexcept
    : name_(another.name()),
      age_(another.age()),
      publications_(another.publications()) {
  std::cout << "[Person] copy constructor: copying " << name_ << std::endl;
}

// 3. move constructor
Person::Person(Person&& another) noexcept
    : name_(another.name()), age_(another.age()) {
  std::cout << "[Person] move constructor: moving " << name_ << std::endl;
}

// 4. destructor
Person::~Person() {
  std::cout << "[Person] destructor: deleting " << name_ << std::endl;
}

// 5. copy assignment operator
Person& Person::operator=(const Person& another) noexcept = default;

// 6. move assignment operator
Person& Person::operator=(Person&& another) noexcept = default;

// bool conversion operator
Person::operator bool() const noexcept { return !name_.empty() && age_ > 0; }

// std::string conversion operator
Person::operator std::string() const noexcept {
  return "Person {name='" + name_ + "', age=" + std::to_string(age_) + " " +
         PublicationsString() + "}";
}

const std::string Person::PublicationsString() const {
  std::string publications_str{"publications={ "};
  for (const auto& weak_book : publications_) {
    if (auto book = weak_book.lock()) publications_str += book->name() + " ";
  }
  publications_str += "}";
  return publications_str;
}

// getters and setters
const std::string Person::name() const { return name_; }

void Person::name(const std::string& new_name) { name_ = new_name; }

const int Person::age() const { return age_; }

void Person::age(const int new_age) { age_ = new_age; }

std::vector<std::weak_ptr<Book>> Person::publications() const {
  return publications_;
}

void Person::publications(
    const std::vector<std::weak_ptr<Book>>& new_publications) {
  publications_ = new_publications;
}

void Person::AddPublication(const std::shared_ptr<Book>& new_publication) {
  // check if new_publication is not already in publications_
  if (std::find_if(
          publications_.begin(), publications_.end(),
          [&new_publication](const std::weak_ptr<Book>& weak_publication) {
            return weak_publication.lock() == new_publication;
          }) == publications_.end()) {
    publications_.push_back(new_publication);
    new_publication->AddAuthor(shared_from_this());
  }
}

void Person::RemovePublication(const std::shared_ptr<Book>& rm_publication) {
  // erase-remove idiom: erase all elements that match the predicate (target
  // book to remove)
  publications_.erase(
      std::remove_if(
          publications_.begin(), publications_.end(),
          [&rm_publication](const std::weak_ptr<Book>& weak_publication) {
            return weak_publication.lock() == rm_publication;
          }),
      publications_.end());
  rm_publication->RemoveAuthor(shared_from_this());
}

void Person::ClearPublications() { publications_.clear(); }

// std::ostream insertion operator
std::ostream& operator<<(std::ostream& os, const Person& person) {
  os << static_cast<std::string>(person);
  return os;
}
