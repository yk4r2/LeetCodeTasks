#include<iostream>
#include<vector>


using std::vector, std::cout, std::endl, std::string, std::max;


class Solution {
 public:
  void nextPermutation(vector<int> nums) {
    if (nums.size() == 1)
      return;
    int right = nums.size() - 1;
    int left = right - 1;
    while (left >= 0 && nums[left] >= nums[right]) {
      left--;
      right--;
    }
    if (left >= 0) {
      int right = nums.size() - 1;
      while (nums[right] <= nums[left])
        right--;
      iter_swap(nums.begin() + right, nums.begin() + left);
    }
    reverse(nums.begin() + left + 1, nums.end());
  }
};


int main() {
  vector<int> input = {0, 2, 5, 8, 17};
  for (auto s : input)
    cout << s << ' ';
  cout << '\n';
  Solution().nextPermutation(input);
  for (auto s : input)
    cout << s << ' ';
  return 0;
}
