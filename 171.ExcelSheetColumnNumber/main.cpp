#include<iostream>
#include<vector>
#include<cmath>


using std::vector, std::cout, std::endl, std::string, std::max, std::pow;


class Solution {
 public:
  int titleToNumber(string columnTitle) {
  int result = 0;
  for (int i = columnTitle.size() - 1; i >= 0; --i)
    result += pow(26, columnTitle.size() - i - 1) * (columnTitle[i] - 'A' + 1);
  return result;
  }
};


int main() {
  cout << Solution().titleToNumber("AAA") << '\n';
  return 0;
}

