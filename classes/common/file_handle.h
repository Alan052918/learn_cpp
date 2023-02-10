#ifndef CLASSES_COMMON_FILE_H_
#define CLASSES_COMMON_FILE_H_

#include <fstream>
#include <iostream>
#include <string>

// RAII style file handler container
class FileHandle {
 public:
  FileHandle(const std::string& filename);

  ~FileHandle();

  void Append(const std::string& content);

 private:
  const std::string filename_;
  std::fstream file_;

 public:
  friend std::ostream& operator<<(std::ostream& os, FileHandle& file_handle);
};

#endif  // CLASSES_COMMON_FILE_H_
