#include<iostream>
#include<vector>

using std::vector, std::cout, std::endl, std::string, std::begin, std::end;


class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
        int low = i + 1;
        int high = nums.size() - 1;
        int temp = 0 - nums[i];
        while (low < high)
          if (nums[low] + nums[high] == temp) {
          vector<int> st;
          st.push_back(nums[i]);
          st.push_back(nums[low]);
          st.push_back(nums[high]);
          ans.push_back(st);
          while (low < high && nums[low] == nums[low + 1])
            low++;
          while (low < high && nums[high] == nums[high - 1])
            high--;
          low++;
          high--;
          } else if (nums[low] + nums[high] > temp) {
            high--;
          } else {
            low++;
          }
      }
    }
    return ans;
  }
};

int main() {
  for (auto i : Solution().threeSum({1, 2, -3, 3, 0})) {
    for (auto j : i)
      cout << j << ' ';
    cout << '\n';
  }
  return 0;
}

