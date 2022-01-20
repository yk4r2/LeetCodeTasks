#include<iostream>
#include<vector>
#include<cmath>


using std::cout, std::endl, std::max, std::vector, std::ceil;


class Solution {
 private:
  bool passes(vector<int> piles, int h, int n) {
    int res = 0;
    for (auto pile : piles) {
      res += ceil(static_cast<double>(pile / n));
    }
    return res <= h;
  }

 public:
  int minEatingSpeed(vector<int> piles, int h) {
    int64 sum = 0;
    for (auto i : piles)
      sum += i;
    int smallest = ceil(static_cast<double>(sum / h));
    int biggest = *max_element(piles.begin(), piles.end());
    if (h == piles.size())
      return biggest;
    int least_true = INT_MAX;
    while (smallest <= biggest) {
      int mid = smallest + (biggest - smallest) / 2;
      if (passes(piles, h, mid)) {
        least_true = mid;
        biggest = mid - 1;
      } else {
        smallest = mid + 1;
    }
  }
  return least_true;
  }
};


int main() {
  vector<int> example = {30, 11, 23, 4, 20};
  cout << Solution().minEatingSpeed(example, 6);
  return 0;
}
