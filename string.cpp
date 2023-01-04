#include <iostream>
#include <string>

void Declaration() {
  // declaration
  std::string name("abcde");
  std::cout << name << std::endl;
}

void ElementAccess() {
  std::string name = "abcde";
  // element access
  std::cout << std::endl << "element access" << std::endl;
  std::cout << name[1] << std::endl;
  std::cout << name.at(2) << std::endl;
  std::cout << name.front() << std::endl;
  std::cout << name.back() << std::endl;
  std::cout << name.c_str() << std::endl;
}

void Iterator() {
  std::string name = "abcde";
  // iterator
  std::cout << std::endl << "iterators" << std::endl;
  std::cout << *name.begin() << " " << typeid(name.begin()).name() << std::endl;
  std::cout << *name.cbegin() << " " << typeid(name.cbegin()).name()
            << std::endl;
  std::cout << *name.rbegin() << " " << typeid(name.rbegin()).name()
            << std::endl;
}

void Capacity() {
  std::string name = "abcde";
  // capacity
  std::cout << std::endl << "capacity" << std::endl;
  std::cout << name.empty() << std::endl;
  std::cout << name.size() << " " << name.length() << std::endl;
  std::cout << name.max_size() << std::endl;
  name = "a";
  std::cout << name.capacity() << std::endl;
  name = "abcdefghijklmnopqrstuv";
  std::cout << name.capacity() << std::endl;
  name = "abcdefghijklmnopqrstuvw";
  std::cout << name.capacity() << std::endl;
  name = "Requests the removal of unused capacity.";
  std::cout << name.capacity() << std::endl;
  name.shrink_to_fit();
  std::cout << name << std::endl;
}

void Operations() {
  std::string name = "abcde";
  // operations
  std::cout << std::endl << "operations" << std::endl;
  name.clear();
  std::cout << name << std::endl;

  name = "abcde";
  name.insert(2, "2");
  std::cout << name << std::endl;
  std::string another = " lalaland";
  name.insert(6, another, 0, another.length());
  std::cout << name << std::endl;

  name.erase(1, 3);
  std::cout << name << std::endl;

  name.push_back('F');
  std::cout << name << std::endl;

  name.pop_back();
  std::cout << name << std::endl;

  name.append("ghijk");
  std::cout << name << std::endl;

  name += "lmnop";
  std::cout << name << std::endl;

  std::cout << name.compare(0, 3, std::string("abc")) << std::endl;
  std::cout << name.compare(0, 3, "ade") << std::endl;
  std::cout << name.compare(0, 3, "bbc") << std::endl;
  std::cout << name.replace(1, 2, "bc") << std::endl;
  std::cout << name.substr(0, 3) << std::endl;

  char* name_copy;
  std::cout << name.copy(name_copy, 5, 0) << std::endl;
  std::cout << name_copy << std::endl;

  name.resize(20, '*');
  std::cout << name << std::endl;

  another = "Hello World";
  std::cout << name << " " << another << std::endl;
  name.swap(another);
  std::cout << name << " " << another << std::endl;
}

void func1(std::string name) { std::cout << name << std::endl; }
void func2(std::string& name) { std::cout << name << std::endl; }
void func3(std::string* name) {
  std::cout << name << std::endl;
  std::cout << *name << std::endl;
}

void PassAsArgument() {
  std::string name = "abcde";
  func1(name);
  func2(name);
  func3(&name);
}

int main() {
  Declaration();
  ElementAccess();
  Iterator();
  Operations();
  PassAsArgument();
}
