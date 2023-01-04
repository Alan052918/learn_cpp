#include "common/file_handle.h"

#include <fstream>
#include <iostream>
#include <string>

FileHandle::FileHandle(const std::string &filename)
    : filename_(filename),
      file_(std::fstream(filename,
                         std::ios::in | std::ios::out | std::ios::trunc)) {
  if (!file_.is_open()) throw std::runtime_error("Error opening file_handle");
  std::cout << "[FileHandle] constructor: opening " << filename_ << std::endl;
}

FileHandle::~FileHandle() {
  file_.close();
  std::cout << "[FileHandle] destructor: closing " << filename_ << std::endl;
}

std::ostream &operator<<(std::ostream &out, FileHandle &file_handle) {
  // set read position to the beginning of the stream
  file_handle.file_.seekg(0, std::ios::beg);

  out << "+-- FileHandle Content --+" << std::endl;
  for (std::string line; std::getline(file_handle.file_, line);)
    out << std::move(line) << std::endl;
  out << "+-- End of FileHandle --+" << std::endl;

  // clear state flags after reading the whole stream (eof bit is set)
  file_handle.file_.clear();

  return out;
}

void FileHandle::Append(const std::string &content) {
  // set write position to the end of the stream
  file_.seekp(0, std::ios::end);

  file_ << content << std::endl;
}
