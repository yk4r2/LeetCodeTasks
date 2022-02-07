#include<iostream>
#include<vector>
#include<unordered_map>


using std::cout, std::endl, std::unordered_map, std::string, std::max;


class Solution {
 public:
  char findTheDifference(string s, string t) {
  char ch = 0;
  for (int i = 0; i < s.size(); ++i) {
    ch ^= s[i];
    ch ^= t[i];
  }
  ch ^= t[t.size() - 1];
  return ch;
  }
};


int main() {
  string input1 = "abcdabcdefbdacb";
  string input2 = "bcadbfedcabcbdae";
  cout << Solution().findTheDifference(input1, input2) << endl;
  return 0;
}
