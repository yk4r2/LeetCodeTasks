#include<iostream>
#include<vector>


using std::vector, std::cout, std::endl, std::string, std::max;


class Solution {
 public:
  int fixedPoint(vector<int> arr) {
    int left = 0, right = arr.size() - 1, answer = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == mid) {
        answer = mid;
        right = mid - 1;
      } else if (arr[mid] < mid) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return answer;
  }
};


int main() {
  vector<int> input = {0, 2, 5, 8, 17};
  cout << Solution().fixedPoint(input) << '\n';
  return 0;
}

