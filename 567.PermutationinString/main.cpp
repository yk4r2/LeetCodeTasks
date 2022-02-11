#include<iostream>


using std::cout, std::endl, std::string, std::begin, std::end, std::equal;


class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;

    int map1[26] = {0};
    int map2[26] = {0};

    for (int i = 0; i < s1.size(); ++i) {
      map1[s1[i] - 'a']++;
      map2[s2[i] - 'a']++;
    }

    for (int i = 0; i < s2.size() - s1.size(); ++i) {
      if (equal(begin(map1), end(map1), begin(map2)))
        return true;
      map2[s2[i + s1.size()] - 'a']++;
      map2[s2[i] - 'a']--;
    }
    return equal(begin(map1), end(map1), begin(map2));
  }
};


int main() {
  cout << Solution().checkInclusion("abcd", "ksksksklabdclls") << '\n';
  return 0;
}

