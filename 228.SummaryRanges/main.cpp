#include<iostream>
#include<string>
#include <vector>


using std::max, std::cout, std::endl, std::string, std::vector, std::to_string;


class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty())
      return {};
    else if (nums.size() < 2)
      return {to_string(nums[0])};
    int fast = 0, slow = 0, prev = nums[slow];
    vector<string> result;

    while (fast < nums.size() && slow < nums.size()) {
      fast++;
      while (fast < nums.size() && prev == nums[fast] - 1) {
        prev = nums[fast];
        fast++;
      }
      if (prev != nums[slow])
        result.push_back(to_string(nums[slow]) + "->" + to_string(prev));
      else
        result.push_back(to_string(prev));
      slow = fast;
      if (slow >= nums.size())
        break;
      prev = nums[slow];
    }
    return result;
  }
};


int main() {
  vector<int> input = {1, 2, 3, 5, 6, 8, 10};
  for (auto element : Solution().summaryRanges(input)) {
    cout << element << " ";
  }
  return 0;
}
