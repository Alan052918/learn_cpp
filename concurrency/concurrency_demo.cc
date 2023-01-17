#include <iostream>
#include <ranges>
#include <thread>
#include <vector>

void ThreadDemo() {
  std::thread t([]() {
    std::cout << "Hello from thread t: " << std::this_thread::get_id()
              << std::endl;
  });
  t.join();
  std::cout << "Hello from main thread: " << std::this_thread::get_id()
            << std::endl;
}

auto lambda = [](int x) {
  std::cout << "thread.get_id(): " << std::this_thread::get_id() << std::endl;
  std::cout << "Argument x: " << x << std::endl;
};

void ThreadWithArgsDemo() {
  std::thread t(lambda, 42);
  t.join();
  std::cout << "Hello from main thread: " << std::this_thread::get_id()
            << std::endl;
}

void ThreadCollectionDemo() {
  std::vector<std::thread> threads;
  for (int i = 0; i < 5; i++) threads.emplace_back(lambda, i);
  for (int i = 0; i < 5; i++) threads[i].join();
  std::cout << "Hello from main thread: " << std::this_thread::get_id()
            << std::endl;
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
