#include<iostream>
#include<vector>


using std::vector, std::cout, std::endl, std::string, std::max;


class Solution {
 public:
  int minNumberOfFrogs(string croakOfFrogs) {
    if (croakOfFrogs.size() % 5)
      return -1;
    int c = 0, r = 0, o = 0, a = 0, result = 0;

    for (auto &s : croakOfFrogs)
      switch (s) {
      case 'c':
        c++;
        break;
      case 'r':
        if (++r > c)
          return -1;
        break;
      case 'o':
        if (++o > r)
          return -1;
        break;
      case 'a':
        if (++a > o)
          return -1;
        break;
      case 'k':
        if (o == 0) {
          return -1;
        } else {
          result = max(result, c--);
          r--, o--, a--;
          break;
        }
      default:
        return -1;
      }
    return (c || r || o || a) ? -1 : result;
  }
};


int main() {
  cout << Solution().minNumberOfFrogs("croackroak") << '\n';
  return 0;
}
