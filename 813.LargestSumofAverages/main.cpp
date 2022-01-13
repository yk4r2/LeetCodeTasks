#include<iostream>
#include<vector>


using std::cout, std::max, std::endl, std::vector, std::min, std::string;


class Solution {
 public:
  double largestSumOfAverages(vector<int> nums, int K) {
    int num_size = nums.size();
    double pref_sum[101];

    for (int i = 0; i < num_size; ++i)
      pref_sum[i + 1] = pref_sum[i] + nums[i];

    double dp[100];
    for (int i = 0; i < num_size; ++i)
      dp[i] = (pref_sum[num_size] - pref_sum[i]) / (num_size - i);

    for (int k = 0; k < K-1; ++k)
      for (int left = 0; left < num_size; ++left)
      for (int right = left + 1; right < num_size; ++right)
        dp[left] = max(dp[left],
               (pref_sum[right] - pref_sum[left]) / (right - left) + dp[right]);
    return dp[0];
  }
};


int main() {
  vector<int> example = {9, 1, 2, 3, 9};
  cout << Solution().largestSumOfAverages(example, 3);
}
