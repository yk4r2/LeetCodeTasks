#include<iostream>
#include<vector>


using std::vector, std::cout, std::endl;


class Solution {
 public:
  int singleNumber(vector<int> nums) {
  int result = 0;
  for (auto num : nums)
    result ^= num;
  return result;
  }
};


int main() {
  cout << Solution().singleNumber({4, 1, 4, 2, 2, 1, 5}) << '\n';
  return 0;
}

