#include<iostream>
#include<vector>
#include<cmath>


using std::cout, std::endl, std::max, std::vector, std::sqrt;


class Solution {
 public:
  bool winnerSquareGame(int n) {
    bool dp[100001] = {false};
    for (int i = 1; i <= n; ++i) {
      int max_square = floor(sqrt(i));
      for (int sqr = 1; sqr <= max_square; ++sqr)
        if (!dp[i - sqr * sqr]) {
          dp[i] = true;
          break;
        }
    }
    return dp[n];
  }
};



int main() {
  cout << Solution().winnerSquareGame(1);
  return 0;
}
