#include<iostream>
#include<vector>
#include<unordered_map>


using std::cout, std::endl, std::unordered_map, std::string, std::max;


class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hashmap;
    hashmap.reserve(256);
    int answer = 0;
    for (int left = 0, right = 0; right < s.size(); right++) {
      if (hashmap[s[right]] != 0)
        left = max(hashmap[s[right]], left);
      answer = max(answer, right - left + 1);
      hashmap[s[right]] = right + 1;
    }
    return answer;
  }
};


int main() {
  string input = "abcdabcdefbdacb";
  cout << Solution().lengthOfLongestSubstring(input) << endl;
  return 0;
}
