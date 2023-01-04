#include <iostream>

// function template
template <typename T>
void Print(T t) {
  std::cout << t << std::endl;
}

// class template
template <typename T, int N>
class Array {
 private:
  T m_Array[N];

 public:
  int GetSize() const { return N; }
};

template void Print<double>(double);
template void Print<>(int);
template void Print(char);

int main() {
  Print<int>(5);
  Print(5.5f);
  Print("Hello World");

  Array<std::string, 50> array;
  std::cout << "array size: " << array.GetSize() << std::endl;
}
