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
 * Delete every node where its value is equal to target and only able to delete the leaf node.
 * And need to take care of the node whcih is initially not leaf node but once the leaf node get deleted it become the
 * leaf node
 *
 *  So what kind of order should we traverse the tree. Since we need to delete node and replace
 *  It best to start from the bottom --> PostOrder
 *  We will start from the bottom so we can handle all those ndoes who are initially not a leaf node
 * */
class Solution
{
  public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        // Base Case
        if (root == nullptr)
        {
            return nullptr;
        }

        // Go to the leaf node first
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // Then only handle the leaf node, so initially non leaf node also can be handle
        if (root->left == nullptr && root->right == nullptr && root->val == target)
        {
            return nullptr;
        }

        return root;
    }
};
