#include<iostream>
#include<vector>


using std::cout, std::endl, std::vector, std::string;


class Solution {
 public:
  string addBinary(string a, string b) {
  int i = a.size() - 1; int j = b.size() - 1; int carry = 0;
  string output;
  while (i >= 0 || j >= 0 || carry) {
    if (i >= 0 && a[i--] == '1') carry++;
    if (j >= 0 && b[j--] == '1') carry++;
    output.insert(0, carry % 2 == 1 ? "1" : "0");
    carry /= 2;
  }
  return output;
  }
};



int main() {
  cout << Solution().addBinary("0", "0");
}
