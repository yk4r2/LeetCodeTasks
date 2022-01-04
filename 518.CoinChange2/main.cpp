#include<iostream>
#include<vector>


using std::vector, std::max, std::fill, std::cout, std::endl;


class Solution {
 public:
  int change(int amount, vector<int>& coins) {
  int dp[++amount];
  fill(dp, dp + amount, 0);
  dp[0] = 1;

  for (auto coin : coins)
    for (int i = coin; i < amount; ++i)
    dp[i] += dp[i-coin];
  return dp[amount-1];
  }
};


int main() {
  vector<int> nums = {1, 2, 5};
  cout << Solution().change(5, nums) << endl;
}
