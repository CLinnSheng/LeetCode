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
 * Goal: Delete every node where its value is equal to target.
 *
 * Intuition:
 * We must start to delete from the leaf node & then go upwards.
 * Since need to start from the bottom, then we need to use postorder traversal
 * */
class Solution
{
  public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (!root)
            return nullptr;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // Delete the node
        // make sure is leaf
        if (!root->left && !root->right && root->val == target)
            return nullptr;

        return root;
    }
};
