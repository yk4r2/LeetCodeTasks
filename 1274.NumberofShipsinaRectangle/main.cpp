#include<iostream>
#include<vector>


using std::cout, std::endl, std::vector, std::string, std::max;


class Solution {
 public:
  int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
    if (topRight == bottomLeft)
      return sea.hasShips(topRight, bottomLeft)?1:0;
    vector<int> halves[2];
    int ret = 0;
    if (topRight[0] - bottomLeft[0] > topRight[1] - bottomLeft[1]) {
      halves[0] = {(topRight[0] + bottomLeft[0] + 1) / 2, bottomLeft[1]};
      halves[1] = {(topRight[0] + bottomLeft[0] - 1) / 2, topRight[1]};
    } else {
      halves[0] = {bottomLeft[0], (topRight[1] + bottomLeft[1] + 1) / 2};
      halves[1] = {topRight[0], (topRight[1] + bottomLeft[1] - 1) / 2};
    }
    if (sea.hasShips(topRight, halves[0]))
      ret += countShips(sea, topRight, halves[0]);
    if (ret == 0 || sea.hasShips(halves[1], bottomLeft))
      ret += countShips(sea, halves[1], bottomLeft);
    return ret;
  }
};


int main() {
  cout << Solution().countShips() << endl;
  return 0;
}
