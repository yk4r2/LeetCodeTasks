#include<iostream>
#include<vector>
#include<unordered_map>


using std::cout, std::endl, std::vector, std::string;
using std::hash, std::unordered_map;


class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> strs) {
    if (!strs.size())
      return {};
    unordered_map<int, vector<string>> hashmap;
    vector<vector<string>> result;

    for (auto s : strs) {
      string key = s;
      sort(key.begin(), key.end());
      hashmap[hash<string>()(key)].push_back(s);
    }
    for (auto kv : hashmap)
      result.push_back(kv.second);
    return result;
  }
};


int main() {
  vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> output = Solution().groupAnagrams(input);
  for (auto group : output) {
    for (auto word : group)
      cout << word << ' ';
    cout << endl;
  }
  return 0;
}
