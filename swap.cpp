#include <iostream>
#include <utility>

int main() {
  int a = 0;
  int b = 1;
  std::cout << a << " " << b << std::endl;
  std::swap(a, b);
  std::cout << a << " " << b << std::endl;
}
