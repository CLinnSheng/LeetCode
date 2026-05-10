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

class Solution
{
  public:
    int maxDepth(TreeNode *root)
    {
        // Just do it recursively and search deep down until we hit the last node
        // And only take the side with larger depth
        if (root == nullptr)
        {
            return 0;
        }

        // Add 1 to depth because if you observe carefully we actually did the computation from the leaf node
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
