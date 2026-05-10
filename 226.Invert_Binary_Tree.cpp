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

#include <utility>
class Solution
{
  public:
    TreeNode *invertTree(TreeNode *root)
    {
        // Do it recursively nodes by nodes
        if (root == nullptr)
        {
            return root;
        }

        std::swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
