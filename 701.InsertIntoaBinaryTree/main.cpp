#include<iostream>
#include<vector>


using std::cout, std::max, std::endl, std::vector, std::min;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  explicit TreeNode(
    int x,
    TreeNode *left,
    TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
  if (!root)
    return new TreeNode(val);

  if (root->val > val)
    root->left = insertIntoBST(root->left, val);
  else
    root->right = insertIntoBST(root->right, val);
  return root;
  }
};


int main() {
  auto right = TreeNode(2);
  auto left = TreeNode(-1);
  auto root = TreeNode(0, &left, &right);
  cout << Solution().insertIntoBST(&root, 3);
}
