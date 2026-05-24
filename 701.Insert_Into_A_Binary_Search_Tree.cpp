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
 * Insert a new node into binary saerch tree
 * Ok so everytime we inserting a new node, it must always obey the BST property
 * Another important thing is insertion is always at the leaf node
 * So we just need to traverse the node according to BST property and insert it
 *
 * Time Complexity: O(h) -> We only search through the tree in one direction
 * Space Complexity: O(h) -> Recursive Call Stack in one direction also
 * */
class Solution
{
  public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // Base Case
        if (root == nullptr)
        {
            // Insert the new node
            return new TreeNode(val);
        }

        // Choose which path based on BST property
        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
