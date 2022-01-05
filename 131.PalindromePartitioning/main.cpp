#include<iostream>
#include<vector>


using std::cout, std::endl, std::vector, std::fill, std::string;


class Solution {
 private:
  bool isPalindrome(string &s, int low, int high) {
  while (low < high)
    if (s[low++] != s[high--])
    return false;
  return true;
  }
  void helper(vector<vector<string>>& res,vector<string>& curr, int i, string &s) {
  if (i >= s.size()) {
    res.push_back(curr);
    return;
  }
  for (int start = i; start < s.size(); ++start)
    if (isPalindrome(s, i, start)) {
    curr.push_back(s.substr(i,start-i+1));
    helper(res, curr, start + 1,s);
    curr.pop_back();
    }
  }
 public:
  vector<vector<string>> partition(string s) {
  vector<vector<string>> res;
  vector<string> curr;
  helper(res,curr,0,s);
  return res;
  }
};



int main() {
  string aab = "aab";
  vector<vector<string>> ans = Solution().partition(aab);
  for (const auto& partition : ans) {
  for (const auto& string : partition)
    cout << '\"' << string << "\" ";
  cout << endl;
  }
}
