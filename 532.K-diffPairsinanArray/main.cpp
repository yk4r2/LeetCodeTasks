#include<iostream>
#include<vector>
#include<unordered_map>


using std::cout, std::endl, std::vector, std::unordered_map, std::max;


class Solution {
 public:
  int findPairs(vector<int> nums, int k) {
    int k_diffs = 0;
    unordered_map<int, int> hashmap;

    for (auto num : nums)
      hashmap[num]++;

    for (auto kv : hashmap) {
      if (!k && kv.second > 1)
      k_diffs++;
      else if (k > 0 && hashmap.find(kv.first + k) != hashmap.end())
      k_diffs++;
    }
    return k_diffs;
  }
};


int main() {
  vector<int> input = {1, 3, 5, 7};
  cout << Solution().findPairs(input, 2) << endl;
  return 0;
}
