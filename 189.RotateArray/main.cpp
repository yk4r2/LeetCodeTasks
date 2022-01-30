#include<iostream>
#include<vector>
#include<stack>


using std::cout, std::endl, std::vector, std::stack, std::max;


class Solution {
 public:
  void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
      int buf = nums[start];
      nums[start] = nums[end];
      nums[end] = buf;
      start++;
      end--;
    }
  }
  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
  }
};


int main() {
  vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  Solution().rotate(input, 4);
  for (auto i : input)
    cout << i << ' ';
  return 0;
}
