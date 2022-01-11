#include<iostream>
#include<vector>


using std::cout, std::max, std::endl, std::vector, std::min;


class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid) {
  int dp[100][100] = {0};

  for (int i = 0; i < obstacleGrid.size(); ++i) {
    if (obstacleGrid[i][0] != 0)
    break;
    dp[i][0] = 1;
  }
  for (int i = 0; i < obstacleGrid[0].size(); ++i) {
    if (obstacleGrid[0][i] != 0)
    break;
    dp[0][i] = 1;
  }

  for (int i = 1; i < obstacleGrid.size(); ++i)
    for (int j = 1; j < obstacleGrid[0].size(); ++j)
    dp[i][j] += !obstacleGrid[i-1][j]
        * dp[i-1][j] + !obstacleGrid[i][j-1] * dp[i][j-1];

  return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1]
    * !obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
  }
};



int main() {
  vector<vector<int>> obstacles = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  cout << Solution().uniquePathsWithObstacles(obstacles);
}
