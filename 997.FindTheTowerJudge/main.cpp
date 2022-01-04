#include<iostream>
#include<vector>


using std::cout, std::endl, std::vector, std::fill;


class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
  if (!trust.size())
    return n == 1 ? 1 : -1;

  int trusted[++n], res = 0, target = n - 2;
  bool trusting[n];

  fill(trusted, trusted + n, 0);
  fill(trusting, trusting + n, false);

  for (auto& e : trust) {
    if (++trusted[e[1]] == target)
    res = e[1];
    trusting[e[0]] = true;
  }
  return !res || trusting[res] ? -1 : res;
  }
};


int main() {
  vector<vector<int>> judge = {{1, 3}, {2, 3}};
  cout << Solution().findJudge(3, judge) << endl;
}
