
#ifndef TEMPLATES_TEMPLATES_LIB_H_
#define TEMPLATES_TEMPLATES_LIB_H_

#include <iostream>

class Foo {
 public:
  Foo(int val);

  // friend templates
  // https://isocpp.org/wiki/faq/templates#template-friends
  // just put the friend template function definition in the class already
  template <typename Container>
  friend std::ostream& operator<<(std::ostream& os, const Container& foos) {
    for (const auto& foo : foos) os << foo.val_ << " ";
    return os;
  }

 private:
  int val_;
};

#endif  // TEMPLATES_TEMPLATES_LIB_H_
