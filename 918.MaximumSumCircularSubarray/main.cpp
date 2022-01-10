#include<iostream>
#include<vector>


using std::cout, std::max, std::endl, std::vector, std::min;


class Solution {
 public:
  int maxSubarraySumCircular(vector<int> nums) {
  int prev_max = nums[0];
  int prev_min = nums[0];
  int max_sum = nums[0];
  int min_sum = nums[0];
  int sum = nums[0];

  for (int i = 1; i < nums.size(); ++i) {
    sum += nums[i];
    prev_max = max(nums[i], nums[i] + prev_max);
    prev_min = min(nums[i], nums[i] + prev_min);
    max_sum = max(max_sum, prev_max);
    min_sum = min(min_sum, prev_min);
  }
  return min_sum == sum ? max_sum : max(sum - min_sum, max_sum);
  }
};



int main() {
  vector<int> prices = {-3, -2, -3};
  cout << Solution().maxSubarraySumCircular(prices);
}
