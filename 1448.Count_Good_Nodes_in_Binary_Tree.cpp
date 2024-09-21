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
 * Goal: Return the number of good nodes
 * Good node: A node X is a good node if in the path from root to X there are no
 * nodes with a value greater than X.
 *
 * Intuition: Can use dfs because we need to check every single node down to the
 * leaf
 *Root node itself is a good node, so this is the maximum value to start with

  Time Complexity: O(n)
  Space Complexity: O(lgn) because of the recursive call
*/
#include <ios>
#include <iostream>
class Solution {
public:
  int goodNodes(TreeNode *root) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::function<int(TreeNode *, int)> dfs = [&](TreeNode *node, int maxVal) {
      if (node == nullptr)
        return 0;

      // Check whether the node pointing now is a goodn node
      int cnt = node->val >= maxVal ? 1 : 0;

      int curr_max = std::max(maxVal, node->val);

      if (node->left)
        cnt += dfs(node->left, curr_max);
      if (node->right)
        cnt += dfs(node->right, curr_max);

      return cnt;
    };

    return dfs(root, root->val);
  }
};
