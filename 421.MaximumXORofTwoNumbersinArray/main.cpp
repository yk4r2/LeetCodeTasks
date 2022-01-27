#include<iostream>
#include<bitset>
#include<vector>
#include<cmath>


using std::cout, std::endl, std::max, std::bitset, std::vector, std::pow;


class TrieNode {
 public:
  TrieNode *child[2];
  TrieNode() {
    this->child[0] = nullptr;
    this->child[1] = nullptr;
  }
};

class Solution {
 public:
  TrieNode* newNode = new TrieNode();

  void insert(int num) {
    TrieNode* tree = newNode;
    bitset<32> bs(num);
    for (int i = 31; i >= 0; --i) {
      if (!tree->child[bs[i]])
      tree->child[bs[i]] = new TrieNode();
      tree = tree->child[bs[i]];
    }
  }

  int maxXOR(int num) {
    bitset<32> bs(num);
    TrieNode* tree = newNode;
    int answer = 0;
    for (int i = 31; i >= 0; --i) {
      if (!tree->child[!bs[i]]) {
        tree = tree->child[bs[i]];
      } else {
        answer += 1 * pow(2, i);
        tree = tree->child[!bs[i]];
      }
    }
    return answer;
  }

  int findMaximumXOR(vector<int> nums) {
    for (auto num : nums)
      insert(num);
    int answer = 0;
    for (auto num : nums) {
      int a = maxXOR(num);
      answer = max(a, answer);
    }
    return answer;
  }
};


int main() {
  vector<int> xors_array = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
  cout << Solution().findMaximumXOR(xors_array) << endl;
  return 0;
}
