#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template <typename M>
void printMap(M& m) {
  cout << "{" << endl;
  for (auto& element : m)
    cout << "\t" << element.first << ": " << element.second << endl;
  cout << "}" << endl;
}

template <typename T>
void printUnoSet(unordered_set<T> unoSet) {
  cout << "set{ ";
  for (const auto& element : unoSet) cout << element << " ";
  cout << "}" << endl;
}

void loopErase() {
  unordered_set<int> numSet({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  printUnoSet<int>(numSet);
  for (auto iter = numSet.begin(); iter != numSet.end();) {
    iter = (*iter & 1) == 1 ? numSet.erase(iter) : std::next(iter);
  }
  printUnoSet<int>(numSet);
}

int main() {
  unordered_map<string, int> payroll;
  payroll.insert(make_pair("adam", 11000));
  payroll.insert({"alan", 10000});
  payroll.emplace("bob", 9000);
  cout << "existent key's value" << payroll.at("alan") << endl;
  cout << "non-existent key's value: " << payroll["cat"] << endl;

  // emplace and insert returns a pair<unordered_map::iterator, bool>
  // first one is an iterator tothe inserted element
  // second one is true if insertion took place, false if no insertion
  const auto& ret = payroll.emplace("dean", 4000);
  cout << "Insert {" << ret.first->first << ", " << ret.first->second << "} "
       << ret.second << endl;

  // find returns an iterator to the element with key
  // or pass-the-end iterator .end() if no element with this key exists
  const auto element = payroll.find("calvin");
  if (element != payroll.end()) {
    cout << "Found " << element->first << " " << element->second << endl;
  } else {
    cout << "Not found" << endl;
  }

  cout << endl << "unordered map mess with insertion order" << endl;
  printMap(payroll);

  map<string, int> ordered_payroll{
      {"adam", 11000}, {"alan", 10000}, {"bob", 9000}, {"dean", 4000}};

  cout << endl << "map reserves insertion order" << endl;
  printMap(ordered_payroll);
  cout << endl;

  loopErase();
}
