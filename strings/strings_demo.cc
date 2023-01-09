#include <iostream>
#include <string>
#include <string_view>

void* operator new(size_t size) {
  std::cout << "Allocating " << size << " bytes" << std::endl;
  return malloc(size);
}

namespace strings::mem {

void Print(const std::string& s) { std::cout << "'" << s << "'"; }

void Println(const std::string& s) {
  Print(s);
  std::cout << std::endl;
}

void Print(const std::string_view s) { std::cout << "view'" << s << "'"; }

void Println(const std::string_view s) {
  Print(s);
  std::cout << std::endl;
}

}  // namespace strings::mem

void MemoryAllocationDemo() {
  std::string hello = "Hello World";
  strings::mem::Println(hello);

  std::string_view hello_view = "Hello World";
  strings::mem::Println(hello_view);
}

namespace strings::trim {

const std::string TrimLeadingZerosVal(std::string s) {
  s.erase(0, s.find_first_not_of('0'));
  if (s.find_first_of('.') == 0) s.insert(0, "0");
  return s;
}

const std::string TrimLeadingZerosInRef(const std::string& str) {
  auto it =
      std::find_if(str.begin(), str.end(), [](char c) { return c != '0'; });
  if (it == str.end()) return "0";
  if (*it == '.') return "0" + std::string(it, str.end());
  return std::string(it, str.end());
}

void TrimLeadingZerosInOutRef(std::string& s) {
  s.erase(0, s.find_first_not_of('0'));
  if (s.find_first_of('.') == 0) s.insert(0, "0");
  if (s.empty()) s = "0";
}

const std::string TrimTrailingZerosVal(std::string s) {
  s.erase(s.find_last_not_of('0') + 1, std::string::npos);
  s.erase(s.find_last_not_of('.') + 1, std::string::npos);
  return s;
}

const std::string TrimTrailingZerosInRef(const std::string& str) {
  auto it =
      std::find_if(str.rbegin(), str.rend(), [](char c) { return c != '0'; });
  if (it == str.rend()) return "0";
  if (*it == '.') return std::string(str.begin(), it.base() - 1);
  return std::string(str.begin(), it.base());
}

void TrimTrailingZerosInOutRef(std::string& s) {
  s.erase(s.find_last_not_of('0') + 1, std::string::npos);
  s.erase(s.find_last_not_of('.') + 1, std::string::npos);
}

void PrintLeadingComparison(std::string& s) {
  strings::mem::Print(s);
  strings::trim::TrimLeadingZerosInOutRef(s);
  std::cout << " -> ";
  strings::mem::Println(s);
}

void PrintTrailingComparison(std::string& s) {
  strings::mem::Print(s);
  strings::trim::TrimTrailingZerosInOutRef(s);
  std::cout << " -> ";
  strings::mem::Println(s);
}

}  // namespace strings::trim

void TrimDemo() {
  std::cout << std::endl << " --- Trim Demo ---" << std::endl;

  std::string s = "  Hello World  ";
  std::cout << "Before: '" << s << "'" << std::endl;

  s.erase(s.find_last_not_of(' ') + 1);
  std::cout << "Trailing whitespaces trimmed: '" << s << "'" << std::endl;

  s.erase(0, s.find_first_not_of(' '));
  std::cout << "Leading whitespaces trimmed: '" << s << "'" << std::endl;

  std::cout << std::endl << "Trim leading zeros:" << std::endl;
  s = "000100.00";
  strings::trim::PrintLeadingComparison(s);
  s = "0100.10";
  strings::trim::PrintLeadingComparison(s);
  s = "0.00";
  strings::trim::PrintLeadingComparison(s);
  s = "000";
  strings::trim::PrintLeadingComparison(s);

  std::cout << std::endl << "Trim trailing zeros:" << std::endl;
  s = "100.00";
  strings::trim::PrintTrailingComparison(s);
  s = "100.10";
  strings::trim::PrintTrailingComparison(s);
  s = "0.00";
  strings::trim::PrintTrailingComparison(s);
  s = "1.23000";
  strings::trim::PrintTrailingComparison(s);

  std::cout << std::endl << " --- Trim Demo exit scope ---" << std::endl;
}

int main() {
  MemoryAllocationDemo();
  TrimDemo();
}
