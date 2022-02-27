#include<iostream>
#include<queue>


using std::max, std::cout, std::endl, std::queue, std::pair, std::make_pair;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) :
    val(x), left(left), right(right) {}
};


class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    if (!root)
      return 0;
    queue<pair<TreeNode*, int>> q;
    unsigned max_width = 0;
    q.push({root, 0});

    while (!q.empty()) {
      int current_size = q.size();
      int min_val = q.front().second;
      unsigned first, last;

      for (int i = 0; i < current_size; ++i) {
        unsigned curr_val = q.front().second - min_val;
        TreeNode *node = q.front().first;
        q.pop();

        if (!i)
          first = curr_val;
        if (i == current_size - 1)
          last = curr_val;

        if (node->left)
          q.push({node->left, 2 * curr_val + 1});
        if (node->right)
          q.push({node->right, 2 * curr_val + 2});
      }
      max_width = max(max_width, last - first + 1);
    }
    return max_width;
  }
};

int main() {
  auto *head = new TreeNode(1);
  head->left = new TreeNode(2);
  head->right = new TreeNode(3);
  head->left->left = new TreeNode(4);
  head->left->right = new TreeNode(5);
  head->right->left = new TreeNode(6);
  cout << Solution().widthOfBinaryTree(head) <<'\n';
  return 0;
}

