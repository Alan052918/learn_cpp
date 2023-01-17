#include <iostream>
#include <ranges>
#include <thread>
#include <vector>

#include "meta/common/demo_wrapper.h"

void ThreadDemo() {
  demo::EnterScope("ThreadDemo");
  std::thread t([]() {
    std::cout << "Hello from thread t: " << std::this_thread::get_id()
              << std::endl;
  });
  t.join();
  std::cout << "Hello from main thread: " << std::this_thread::get_id()
            << std::endl;
  demo::ExitScope("ThreadDemo");
}

auto lambda = [](int x) {
  std::cout << "thread.get_id(): " << std::this_thread::get_id() << std::endl;
  std::cout << "Argument x: " << x << std::endl;
};

void ThreadWithArgsDemo() {
  demo::EnterScope("ThreadWithArgsDemo");
  std::thread t(lambda, 42);
  t.join();
  std::cout << "Hello from main thread: " << std::this_thread::get_id()
            << std::endl;
  demo::ExitScope("ThreadWithArgsDemo");
}

void ThreadCollectionDemo() {
  demo::EnterScope("ThreadCollectionDemo");
  const auto cpu_cores = std::thread::hardware_concurrency();
  std::cout << "cpu_cores: " << cpu_cores << std::endl;
  std::vector<std::thread> threads;
  for (int i = 0; i < cpu_cores; i++) threads.emplace_back(lambda, i);
  for (int i = 0; i < cpu_cores; i++) threads[i].join();
  std::cout << "Hello from main thread: " << std::this_thread::get_id()
            << std::endl;
  demo::ExitScope("ThreadCollectionDemo");
}

// void JThreadDemo() {
//   std::vector<std::jthread> jthreads;
//   std::cout << "Hello from main thread: " << std::this_thread::get_id()
//             << std::endl;
// }

int main(int argc, char const* argv[]) {
  ThreadDemo();
  ThreadWithArgsDemo();
  ThreadCollectionDemo();
}
