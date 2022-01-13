#include<iostream>
#include<vector>


using std::cout, std::max, std::endl, std::vector, std::min;


class Solution {
 private:
  static const bool comparer(vector<int>& a, vector<int>& b) {
  return a[1] < b[1];
  }
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
  sort(points.begin(), points.end(), comparer);
  int right = points[0][1];
  int current = 1;

  for (int i = 1; i < points.size(); ++i)
    if (points[i][0] <= right) {
    continue;
    } else {
    current++;
    right = points[i][1];
    }
  return current;
  }
};


int main() {
  vector<vector<int>> grid = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  cout << Solution().findMinArrowShots(grid);
}
