/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Given a binary search tree (BST) where all node values are unique, and two nodes from the tree p and q, return the lowest common ancestor (LCA) of the two nodes.
The lowest common ancestor between two nodes p and q is the lowest node in a tree T such that both p and q as descendants. The ancestor is allowed to be a descendant of itself.

Intuition: The root node is the common ancestor for all the nodes & also make use of BST property
if the 2 nodes not come from the same substree that means the common ancestor happen to be the node before it split into half
So basically we have to check whether the 2 nodes happen to be in the same substree or not loop until they are not belong to the same tree.
Special case where one of the node might be ancestor where they kinda in the same tree but pratically not
eg:     2
      /   \
    3      4
    Common Ancestor of 2 & 4 is 2
Time Complexity: O(n)
Space complexity: O(1)
*/

#include <ios>
#include <iostream>
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        // keep looping until the both nodes in the asme substre
        while (true)
        {
            // right subtree    
            if (root->val < p->val && root->val < q->val) root = root->right;
            // left subtree
            else if (root->val > p->val && root->val > q->val) root = root->left;
            // found in the same subtree 
            else return root;
        }
        
        return nullptr;
    }
};