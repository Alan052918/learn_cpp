#include <iostream>
#include <tuple>
#include <vector>

struct ListNode {};

using list_node = std::tuple<int, int, ListNode*>;
auto list_node_compare = [](const list_node& ln1, const list_node& ln2) {
  int val1, val2, counter1, counter2;
  std::tie(val1, counter1, std::ignore) = ln1;
  std::tie(val2, counter2, std::ignore) = ln2;
  // return val1 > val2 || counter1 > counter2;
  return std::tie(val1, counter1) > std::tie(val2, counter2);
};

int main(int argc, char** argv) {
  std::vector<list_node> list_nodes{
      {1, 3, nullptr}, {2, 2, nullptr}, {3, 1, nullptr}};
  std::sort(list_nodes.begin(), list_nodes.end(), list_node_compare);
  for (const auto& ln : list_nodes) {
    int val, counter;
    std::tie(val, counter, std::ignore) = ln;
    std::cout << val << " " << counter << std::endl;
  }
}
