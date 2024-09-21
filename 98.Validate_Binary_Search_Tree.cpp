/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
 * Goal: Determine if the tree is a valid BST or not
 * Intuition: Traverse through every node and check at every node
 * IMPORTANT: It must be consistent throughout the tree (BST property)
 * Time Complexity: O(n)
 * Space Complexity: O(lgn)
 */
class Solution {
public:
  bool isValidBST(TreeNode *root) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (!root)
      return true;

    std::function<bool(TreeNode *, long, long)> dfs =
        [&](TreeNode *node, long left, long right) {
          if (!node)
            return true;

          // for the left subtree, we only need to take care of the right
          // maximum value because for the left is always negative inf same goes
          // to the right in the opposite way
          if (!(node->val > left && node->val < right))
            return false;

          return dfs(node->left, left, node->val) &&
                 dfs(node->right, node->val, right);
        };

    return dfs(root, LONG_MIN, LONG_MAX);
  }
};
