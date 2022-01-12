#include<iostream>
#include<vector>


using std::cout, std::max, std::endl, std::vector, std::min;


class Solution {
 public:
  int minPathSum(vector<vector<int>> grid) {
  for (int i = 0; i < grid.size(); ++i)
    for (int j = 0; j < grid[0].size(); ++j) {
    if (i == 0 && j == 0)
      continue;

    int up = j > 0 ? grid[i][j] + grid[i][j - 1] : INT_MAX;
    int down = i > 0 ? grid[i][j] + grid[i - 1][j] : INT_MAX;
    grid[i][j] = min(up, down);
    }
  return grid[grid.size() - 1][grid[0].size() - 1];
  }
};


int main() {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << Solution().minPathSum(grid);
}
