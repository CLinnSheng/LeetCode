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
Goal: Return the inverted tree

Time Complexity: O(n) because we visiting every single node
Space Complexity: O(n + logn) n is due to the number of node it created every time we visit a node
logn is the height of tree because of the recursive call will create a stack with logn which is the height of the tree
*/

class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr) return nullptr;
        
        TreeNode* node = new TreeNode(root->val)
        
        node->left = inverTree(root->right);
        node->right = inverTree(root->left);
        
        return node;
    }
        
    
};