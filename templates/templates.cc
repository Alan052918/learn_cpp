#include <iostream>
#include <memory>
#include <type_traits>
#include <vector>

class Person {
 public:
  Person(const std::string& name) : name_(name) {}
  const std::string& GetName() const { return name_; }

  friend std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.name_;
    return os;
  }

  template <typename Container>
  friend typename std::enable_if<std::is_same<typename Container::value_type,
                                              std::weak_ptr<Person>>::value,
                                 std::ostream&>::type
  operator<<(std::ostream& os, const Container& people) {
    os << "People: ";
    for (const auto& person : people) {
      if (auto p = person.lock()) {
        os << p->GetName() << " ";
      }
    }
    return os;
  }

 private:
  std::string name_;
};

int main() {
  std::vector<std::weak_ptr<Person>> people_vec;

  Person alice{"Alice"};
  std::cout << "alice: " << alice.GetName() << std::endl;

  auto shared_alice = std::make_shared<Person>(alice);
  std::cout << "shared_alice: " << shared_alice->GetName() << std::endl;

  people_vec.push_back(shared_alice);
  std::cout << "back of people: " << people_vec.back().lock()->GetName()
            << std::endl;

  auto shared_bob = std::make_shared<Person>("Bob");
  people_vec.push_back(shared_bob);
  std::cout << "back of people: " << people_vec.back().lock()->GetName()
            << std::endl;

  std::cout << people_vec << std::endl;  // Outputs "People: Alice Bob Eve "
}
