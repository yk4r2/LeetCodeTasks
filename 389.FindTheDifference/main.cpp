#include<iostream>
#include<vector>
#include<unordered_map>


using std::cout, std::endl, std::unordered_map, std::string, std::max;


class Solution {
 public:
  char findTheDifference(string s, string t) {
    int alph[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
      alph[s[i] - 'a']++;
      alph[t[i] - 'a']--;
    }
    alph[t[t.size() - 1] - 'a']--;
    for (int w = 0; w < 26; ++w)
      if (alph[w] != 0)
      return 'a' + w;
    return ' ';
  }
};


int main() {
  string input1 = "abcdabcdefbdacb";
  string input2 = "bcadbfedcabcbdae";
  cout << Solution().findTheDifference(input1, input2) << endl;
  return 0;
}
