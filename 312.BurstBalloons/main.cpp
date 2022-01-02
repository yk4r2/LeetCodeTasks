#include<iostream>
#include<vector>

using std::vector, std::max, std::fill, std::cout, std::endl;

int memo[501][501];
vector<int> arr;

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size(), gap, left, mid;
    arr.resize(n + 2);
    arr[0] = 1;
    for (left = 0; left < n; left++)
      arr[left + 1] = nums[left];
    arr[n + 1] = 1;

    for (left = 1; left <= n; left++)
      memo[left][left] = arr[left] * arr[left - 1] * arr[left + 1];

    for (gap = 2; gap <= n; gap++) {
      for (left = 1; left <= n - gap + 1; left++) {
        int right, maxi = 0;
          right = left + gap - 1;
        for (mid = left; mid <= right; mid++) {
          int preleft = mid == left ? 0 : memo[left][mid - 1];
          int preright = mid == right ? 0 : memo[mid + 1][right];
          maxi = max(
            maxi,
            preleft + preright + arr[mid] * arr[left - 1] * arr[right + 1]);
        }
        memo[left][right] = maxi;
      }
    }
    return memo[1][n];
  }
};


int main() {
  vector<int> balloons = {3, 1, 5, 8};
  cout << Solution().maxCoins(balloons) << endl;
}
