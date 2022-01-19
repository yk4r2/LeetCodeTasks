#include<iostream>
#include<vector>


using std::cout, std::endl, std::max, std::vector;


class Solution {
 public:
  int trap(vector<int>& height) {
    int left = 0, right = static_cast<int>(height.size() - 1);
    int level = 0;
    int result = 0;
    while (right > left) {
      int lowest = height[height[left] < height[right] ? left++ : right--];
      level = max(level, lowest);
      result += level - lowest;
    }
    return result;
  }
};


int main() {
  vector<int> example = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << Solution().trap(example);
  return 0;
}
