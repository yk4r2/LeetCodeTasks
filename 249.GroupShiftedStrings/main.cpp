#include<iostream>
#include<vector>
#include<unordered_map>


using std::cout, std::endl, std::vector, std::string, std::unordered_map;


class Solution {
 public:
  static char shiftLetter(char letter, int shift) {
    return (letter - shift + 26) % 26 + 'a';
  }

  static string getHash(string str) {
    int shift = str[0];
    string hashingKey;

    for (char letter : str)
      hashingKey += shiftLetter(letter, shift);
    return hashingKey;
  }

  vector<vector<string>> groupStrings(vector<string> strings) {
    unordered_map<string, vector<string>> hashmap;
    for (auto str : strings)
      hashmap[getHash(str)].push_back(str);

    vector<vector<string>> grouped;
    for (const auto& it : hashmap)
      grouped.push_back(it.second);
    return grouped;
  }
};


int main() {
  vector<string> input = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
  vector<vector<string>> result = Solution().groupStrings(input);
  for (const auto& vec : result) {
    for (const auto& word : vec)
      cout << word << ' ';
    cout << endl;
  }
  return 0;
}
