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
 * We need to delete every leaf node where its value is equal to target. But how can we delete and traverse the tree?
 * There is 4 ways to traverse, inorder, preorder, postorder, and level order.
 * So is much more easier to build a tree that deleteing the node from the bottom
 * Therefore, we need to use postorder traversal.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (!root)
        {
            return nullptr;
        }

        TreeNode *left = removeLeafNodes(root->left, target);
        TreeNode *right = removeLeafNodes(root->right, target);

        // Make sure is a leaf node
        if (left == nullptr && right == nullptr && root->val == target)
        {
            return nullptr;
        }

        root->left = left;
        root->right = right;

        return root;
    }
};
