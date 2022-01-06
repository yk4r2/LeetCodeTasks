#include<iostream>
#include<vector>


using std::cout, std::endl, std::string, std::fill, std::min, std::max, std::fill;


class Solution {
 public:
  int numDecodings(string s) {
  if (s[0] == '0')
    return 0;
  if (s.size() == 1)
    return 1;

  int slen = s.size();
  int dp[3];

  dp[0] = 1;
  dp[1] = (s[0] == '1' || s[0] == '2' && s[1] < '7' ? 1 : 0) + (s[1] != '0');

  for (int i = 2, curr, prev; i < slen; ++i) {
    curr = i % 3;
    prev = (i - 1) % 3;
    if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0'))
    return 0;

    dp[curr] = s[i] != '0' ? dp[prev] : 0;

    if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7')
    dp[curr] += dp[(i - 2) % 3];
  }
  return dp[(slen - 1) % 3];
  }
};


int main() {
  cout << Solution().numDecodings("10");
}
