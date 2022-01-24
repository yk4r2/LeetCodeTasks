#include<iostream>
#include<string>


using std::cout, std::endl, std::max, std::string;


class Solution {
 public:
  static bool isUpper(char c) {
  return c > 64 && c < 91;
  }
  bool detectCapitalUse(string w) {
  return all_of(w.begin(), w.end(), isUpper)
         || none_of(w.begin() + 1, w.end(), isUpper);
  }
};


int main() {
  cout << Solution().detectCapitalUse("FlaG") << endl;
  return 0;
}
