#include<iostream>
#include<vector>


using std::cout, std::endl;


class Solution {
 public:
  int bitwiseComplement(int N) {
  return (int)(0xFFFFFFFF >> __builtin_clz(N | 1) ^ N);
  }
};

int main() {
  cout << Solution().bitwiseComplement(15) << endl;
}
