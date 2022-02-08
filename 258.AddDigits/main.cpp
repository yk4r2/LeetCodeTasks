#include<iostream>
#include<vector>


using std::cout, std::endl, std::vector, std::string, std::max;


class Solution {
 public:
  int addDigits(int num) {
    int subnum = 0;
    while (num >= 10) {
      while (num) {
      subnum += num % 10;
      num /= 10;
      }
      num = subnum;
      subnum = 0;
    }
    return num;
  }
};


int main() {
  cout << Solution().addDigits(38) << endl;
  return 0;

