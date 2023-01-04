#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// RAII style file handler container
class File {
  std::fstream file_;

 public:
  File(const std::string& filename)
      : file_(std::fstream(filename,
                           std::ios::in | std::ios::out | std::ios::trunc)) {
    if (!file_.is_open()) throw std::runtime_error("Error opening file");
    std::cout << "**File constructor: file opened" << std::endl;
  }

  ~File() {
    file_.close();
    std::cout << "**File destructor: file closed" << std::endl;
  }

  void printAllLines(std::ostream& stream) {
    // set read position to the beginning of the stream
    file_.seekg(0, std::ios::beg);

    std::cout << "+-- File Content --+" << std::endl;
    for (std::string line; std::getline(file_, line);)
      stream << line << std::endl;
    std::cout << "+-- End of File --+" << std::endl << std::endl;

    file_.clear();  // clear state flags after reading the whole stream (eof bit
                    // is set)
  }

  void append(const std::string& content) {
    // set write position to the end of the stream
    file_.seekp(0, std::ios::end);

    file_ << content << std::endl;
  }
};

int main(int argc, char const* argv[]) {
  try {
    File file("myfile.txt");

    file.append("Hello, World!");
    file.append("42");
    file.printAllLines(std::cout);

    file.append("I'm Junda.");
    file.printAllLines(std::cout);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
