/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
 * Check whether a tree is a valid BST
 * So tree problem either bfs/dfs
 * DFS -> Recursive
 * DFS will be much more simpler in this case
 *
 * So we just need to check the tree according to the BST property and check from the leaf up to the tree
 * And also we need to pass down the information of the maxVal & minVal allow.
 * For instance all the nodes in the left subtree must be smaller than the node and vice versa for the right subtree
 * */
#include <climits>
class Solution
{
  public:
    bool isValidBST(TreeNode *root)
    {
        auto dfs = [](this auto self, TreeNode *node, long minVal, long maxVal) {
            // Base Case
            if (node == nullptr)
            {
                return true;
            }

            // Check whether follow the BST property or not
            if (node->val >= maxVal || node->val <= minVal)
            {
                return false;
            }

            return self(node->left, minVal, node->val) && self(node->right, node->val, maxVal);
        };

        return dfs(root, LONG_MIN, LONG_MAX);
    }
};
