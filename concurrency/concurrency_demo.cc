#include <iostream>
#include <thread>

#include "meta/common/demo_wrapper.h"

auto ThreadDemo = []() {
  std::thread t([]() {
    std::cout << "Hello from thread t: " << std::this_thread::get_id()
              << std::endl;
  });
  t.join();
  std::cout << "Hello from main thread: " << std::this_thread::get_id()
            << std::endl;
};

int main(int argc, char const* argv[]) { demo::Run("ThreadDemo", ThreadDemo); }
