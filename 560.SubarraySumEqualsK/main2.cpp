#include<iostream>
#include<vector>
#include<unordered_map>


using std::cout, std::endl, std::vector, std::unordered_map, std::max;


class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> hashmap;
    hashmap.reserve(4*10000);
    int sum = 0;
    int result = 0;
    ++hashmap[sum];
    for (auto it : nums) {
      sum += it;
      result += hashmap[sum - k];
      hashmap[sum]++;
    }
    return result;
  }
};



int main() {
  vector<int> input = {1, 3, -7, 7};
  cout << Solution().subarraySum(input, 4) << endl;
  return 0;
}
