#include<iostream>
#include<vector>


using std::cout, std::endl, std::max, std::vector;


class Solution {
 public:
  int maxDistToClosest(vector<int> seats) {
    int counter = seats[0] == 0 ? 1 : 0;
    int max_nulls = 0;
    for (auto seat : seats) {
      if (!seat) {
        counter++;
        max_nulls = max(max_nulls, (counter + 1) / 2);
      } else {
        counter = 0;
      }
    }
    for (int i = 0; i < seats.size(); ++i)
      if (seats[i] == 1) {
        max_nulls = max(max_nulls, i);
        break;
      }
    for (int i = seats.size() - 1; i >= 0; --i)
      if (seats[i] == 1) {
        max_nulls = max(max_nulls, static_cast<int>(seats.size() - i - 1));
        break;
      }
    return max_nulls;
  }
};


int main() {
  vector<int> example = {1, 0, 0, 0, 1, 0, 1};
  cout << Solution().maxDistToClosest(example);
}
