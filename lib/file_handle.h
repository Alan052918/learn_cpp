#ifndef LIB_FILE_H_
#define LIB_FILE_H_

#include <fstream>
#include <iostream>
#include <string>

// RAII style file handler container
class FileHandle {
 public:
  FileHandle(const std::string& filename);

  ~FileHandle();

  friend std::ostream& operator<<(std::ostream& out, FileHandle& file_handle);

  void Append(const std::string& content);

 private:
  const std::string filename_;
  std::fstream file_;
};

#endif  // LIB_FILE_H_
