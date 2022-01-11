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
 private:
  int recursionSum(TreeNode* head, int res) {
  if (!head) return 0;

  res = 2 * res + head->val;
  if (head->left == nullptr && head->right == nullptr)
    return res;
  else
    return recursionSum(head->left, res) + recursionSum(head->right, res);
  }
 public:
  int sumRootToLeaf(TreeNode* root) {
  return recursionSum(root, 0);
  }
};



int main() {
  auto right = TreeNode(0);
  auto left = TreeNode(1);
  auto head = TreeNode(1, &left, &right);
  cout << Solution().sumRootToLeaf(&head);
}
