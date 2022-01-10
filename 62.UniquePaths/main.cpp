#include<iostream>
#include<vector>


using std::cout, std::max, std::endl, std::vector, std::min;


class Solution {
 public:
  int uniquePaths(int m, int n) {
  int dp[100][100] = {0};
  dp[0][0] = 1;

  for (int row = 0; row < m; ++row)
    for (int col = 0; col < n; ++col) {
    if (row > 0)
      dp[row][col] += dp[row-1][col];
    if (col > 0)
      dp[row][col] += dp[row][col-1];
    }
  return dp[m - 1][n - 1];
  }
};



int main() {
  cout << Solution().uniquePaths(3, 7);
}
