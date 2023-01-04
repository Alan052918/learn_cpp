#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  stringstream ss(
      "1 # 2 3 4 5 # # 6 7 # 8 # 9 10 # # 11 # 12 # 13 # # 14 # # # #");
  int val;

  while (ss >> val || !ss.eof()) {
    if (ss.fail()) {
      ss.clear();
      string end_children;
      ss >> end_children;
      continue;
    }

    cout << val << endl;
  }

  stringstream ss("hello, world, I'm Alan, nice to meet you");
  string token;
  getline(ss, token, ',');
  cout << token << endl;

  stringstream ss("1 abc");
  string str;
  int i;
  ss >> i;
  cout << i << endl;
}
