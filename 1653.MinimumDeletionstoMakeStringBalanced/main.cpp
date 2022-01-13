#include<iostream>
#include<vector>


using std::cout, std::max, std::endl, std::vector, std::min, std::string;


class Solution {
 public:
  int minimumDeletions(string s) {
    int b_count = 0, result = 0;

    for (auto& word : s) {
      if (word == 'a')
      result = min(++result, b_count);
      else
      ++b_count;
    }
    return result;
  }
};


int main() {
  cout << Solution().minimumDeletions("aabababababbb");
}
