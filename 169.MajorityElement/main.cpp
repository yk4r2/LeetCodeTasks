#include<iostream>
#include<vector>


using std::vector, std::cout, std::endl;


class Solution {
 public:
  int majorityElement(vector<int> nums) {
  int count = 0;
  int cand = 0;
  for (int num : nums) {
    if (count == 0)
    cand = num;
    count += (num == cand) ? 1 : -1;
  }
  return cand;
  }
};


int main() {
  vector<int> nums = {4, 1, 4, 2, 2, 1, 5, 4, 4, 4, 4, 4};
  cout << Solution().majorityElement(nums) << '\n';
  return 0;
}

