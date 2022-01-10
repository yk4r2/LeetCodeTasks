#include<iostream>
#include<vector>


using std::cout, std::max, std::endl, std::vector;


class Solution {
 public:
  int maxProfit(vector<int> prices) {
    int biggest_diff = INT_MIN;
    int current_max = INT_MIN;
    for (int i = prices.size() - 1; i >= 0; --i) {
      current_max = max(current_max, prices[i]);
      biggest_diff = max(current_max - prices[i], biggest_diff);
    }
    return biggest_diff;
  }
};



int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << Solution().maxProfit(prices);
}
