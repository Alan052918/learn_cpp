#include <fstream>
#include <iostream>
#include <string>

void consecutiveReadAndWrite() {
  std::fstream file("myfile.txt");  // open the file for writing
  file << "Hello, World!" << std::endl;
  file << 42 << std::endl;
  file << 33 << std::endl;
  file << 12 << std::endl;

  // sets input (read) position indicator to the beginning of the stream
  file.seekg(0, std::ios::beg);
  for (std::string line; std::getline(file, line);)
    std::cout << line << std::endl;
  // clear state flags after reading the whole stream (eof bit is set)
  file.clear();

  // sets output (write) position indicator to the end of the stream
  file.seekp(0, std::ios::end);
  file << 22 << std::endl;

  // sets input (read) position indicator to the beginning of the stream
  file.seekg(0, std::ios::beg);
  for (std::string line; std::getline(file, line);)
    std::cout << line << std::endl;
  // clear state flags after reading the whole stream (eof bit is set)
  file.clear();

  file.close();  // close the file
}

int main() { consecutiveReadAndWrite(); }
