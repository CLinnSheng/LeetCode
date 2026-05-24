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
 * Deleting a node in BST
 * So same rule applies to how we apply insertion
 * But over here we need to take care of how to relink the tree after deletion
 *
 * So everytime we delete a node, we need to find a node to replace its existing position?
 * So which node should we refer to? The next element greater than the node being replaced
 * How do we find it, go to the right part of the tree then keep traverse to the end on the left
 *
 * Multiple Case of Deletion
 * 1. Leaf Node -> Just simply return nullptr
 * 2. Has only one child -> Just replaced by the child
 * 3. Has 2 child -> Then need to find the next element greater than it
 *
 * Use recursion and rebuild the tree by keep returning the subtree
 *
 * Time Complexity: O(h) because we only search deep on one direction
 * Space Complexity: O(h) -> Recursive Call Stack in one direction also
 * */
class Solution
{
  public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // Base Case -> reach the end but still couldnt find it
        if (root == nullptr)
        {
            return nullptr;
        }

        // Keep finding the node
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Case 1: Leaf Node & Case 2: One child
            if (root->left == nullptr || root->right == nullptr)
            {
                TreeNode *child = root->left ? root->left : root->right;
                delete root;
                return child;
            }

            // Case 3
            // Need to find the node to replace the removed node
            TreeNode *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            // Replace the removed node
            root->val = temp->val;
            // Removed the node
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};
