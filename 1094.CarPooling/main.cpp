#include<algorithm>
#include<iostream>
#include<vector>


using std::cout, std::endl, std::vector, std::fill, std::min, std::max, std::fill;


class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
  int tMin = INT_MAX, tMax = INT_MIN, currentPassengerNumber = 0;
  for (vector<int> t : trips) {
    tMin = min(tMin, t[1]);
    tMax = max(tMax, t[2]);
  }

  int travel[tMax - tMin + 1];
  for (int& t : travel)
    t = 0;

  for (vector<int> t : trips) {
    travel[t[1] - tMin] += t[0];
    travel[t[2] - tMin] -= t[0];
  }

  for (int t : travel) {
    if (t) {
    currentPassengerNumber += t;
    if (currentPassengerNumber > capacity)
      return false;
    }
  }
  return true;
  }
};


int main() {
  vector<vector<int>> inp = {{3, 2, 7}, {3, 7, 9}, {8, 3, 9}};
  cout << Solution().carPooling(inp, 11);
}
