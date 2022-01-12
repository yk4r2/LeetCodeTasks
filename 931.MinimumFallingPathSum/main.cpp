#include<iostream>
#include<vector>


using std::cout, std::max, std::endl, std::vector, std::min;


class Solution {
 public:
  int minFallingPathSum(vector<vector<int>> matrix) {
  int n = matrix.size();
  if (n == 1)
    return matrix[0][0];

  for (int i = n - 2; i >= 0; --i) {
    // left-side (no -1 element here)
    matrix[i][0] += min(matrix[i + 1][0], matrix[i + 1][1]);
    // right-side (no n element here)
    matrix[i][n - 1] += min(matrix[i + 1][n - 1], matrix[i + 1][n - 2]);
    for (int j = 1; j < n - 1; ++j) {
    matrix[i][j] += min(
      min(matrix[i + 1][j], matrix[i + 1][j - 1]),
      matrix[i + 1][j + 1]);
    }
  }
  return *min_element(matrix[0].begin(), matrix[0].end());
  }
};


int main() {
  vector<vector<int>> grid = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  cout << Solution().minFallingPathSum(grid);
}
