#include<iostream>
#include<vector>


using std::cout, std::endl, std::vector, std::string, std::max;


class Solution {
 public:
  int maximumWealth(vector<vector<int>> accounts) {
    int max_wealth = 0;
    for (auto customer : accounts) {
      int wealth = 0;
      for (auto money : customer)
      wealth += money;
      max_wealth = max(wealth, max_wealth);
    }
    return max_wealth;
  }
};


int main() {
  vector<vector<int>> input = {{1, 2, 3}, {3, 2, 1}};
  cout << Solution().maximumWealth(input) << endl;
  return 0;
}
