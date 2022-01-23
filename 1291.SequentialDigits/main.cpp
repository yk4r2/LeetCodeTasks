#include<iostream>
#include<vector>


using std::cout, std::endl, std::max, std::vector;


class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;
    int sum;
    for (int left = 1; left <= 9; left++) {
      sum = 0;
      for (int right = left; right <= 9; right++) {
        sum = sum * 10 + right;
        if (sum >= low && sum <= high)
          ans.push_back(sum);
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};



int main() {
  for (auto num : Solution().sequentialDigits(100, 2000))
    cout << num << endl;
  return 0;
}
