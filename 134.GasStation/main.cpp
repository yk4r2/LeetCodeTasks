#include<iostream>
#include<vector>


using std::cout, std::endl, std::max, std::vector;


class Solution {
 public:
  int canCompleteCircuit(vector<int> gas, vector<int> cost) {
    int current_money = 0;
    int start = 0;
    int now = 0;
    while (start < gas.size()) {
      current_money += gas[now];
      if (current_money >= cost[now]) {
        current_money -= cost[now];
        now = (now + 1) % gas.size();
      if (start == now)
        return now;
      } else {
        now += 1;
        current_money = 0;
        if (start < now)
          start = now;
        else
          return -1;
      }
    }
    return -1;
  }
};


int main() {
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  cout << Solution().canCompleteCircuit(gas, cost);
  return 0;
}
