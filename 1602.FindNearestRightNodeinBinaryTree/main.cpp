#include<iostream>
#include<vector>
#include<queue>


using std::cout, std::endl, std::max, std::vector, std::queue;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x,
           TreeNode *left,
           TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
    if (root == nullptr)
      return nullptr;

    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
      TreeNode* current = q.front();
      q.pop();
      if (current != nullptr) {
        if (current == u)
          return q.front();

        if (current->left != nullptr)
          q.push(current->left);
        if (current->right != nullptr)
          q.push(current->right);
      } else {
        if (!q.empty())
          q.push(nullptr);
      }
    }
    return nullptr;
  }
};



int main() {
  cout << Solution().findNearestRightNode();
  return 0;
}
