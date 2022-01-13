#include<iostream>
#include<vector>


using std::cout, std::max, std::endl, std::vector, std::min, std::string;


class Solution {
 public:
  bool checkString(string s) {
    bool flag = false;
    for (auto ch : s) {
      if (flag && ch == 'a')
      return false;
      flag = ch == 'b';
    }
    return true;
  }
};


int main() {
  cout << Solution().checkString("aabbbbb");
}
