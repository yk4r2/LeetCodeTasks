#include<iostream>
#include<vector>


using std::cout, std::endl, std::vector, std::max;


class Solution {
 public:
  static int cherryPickup(vector<vector<int>>& grid) {
  // n :: rows count, m :: columns count in the grid
  int m = (int) grid.size();
  int n = (int) grid[0].size();
  // memo :: DP caching array (size chosen due to constraints)
  int memo[70][70][70] = {-1};

  // Let us prefill the last row
  for (int row = m - 1; row >= 0; --row)
    for (int col1 = 0; col1 < n; ++col1)
    for (int col2 = 0; col2 < n; ++col2)
      // Little speed-up from no-branch programming
      // + (condition) * (smth) means we add (smth) if condition is met
      memo[row][col1][col2] = grid[row][col1] + (col1 != col2) * grid[row][col2];

  // First let us iterate through all the rows bottom >> up
  // Robot 1 (col1): left >> right, Robot 2 (col2): right >> left;
  for (int row = m - 2; row >= 0; --row)
    for (int col1 = 0; col1 < n; ++col1)
    for (int col2 = 0; col2 < n; ++col2) {
      // Little speed-up from no-branch programming
      // + (condition) * (smth) means we add (smth) if condition is met
      memo[row][col1][col2] = grid[row][col1] + (col1 != col2) * grid[row][col2];
      int max_cherries = 0;
      // Robot could come to current (row, col1, col2) only from
      // (row - 1, col1 ± 1, col2 ± 1) due to constraints
      for (int new1 = col1 - 1; new1 <= col1 + 1; ++new1)
      for (int new2 = col2 - 1; new2 <= col2 + 1; ++new2)
        // This is just a constraints checker, looks awful, I know
        if (new1 >= 0 && new1 < n && new2 >= 0 && new2 < n)
        max_cherries = max(max_cherries, memo[row + 1][new1][new2]);
      memo[row][col1][col2] += max_cherries;
    }
  return memo[0][0][n-1];
  }
};


int main() {
  vector<vector<int>> grid = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
  cout << Solution::cherryPickup(grid);
}
