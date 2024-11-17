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
Goal: Check whether the 2 tree are the same or not based on the structure and the value of every single node
Intuition: Check every single node are they equal or not
Recursive call

Time Complexity: O(n) checking every single node
Space Complexity: O(lgn)
where n is the number of nodes for the shorter tree, because we dont have go search depper as they are already not equal
*/
#include <deque>
class Solution 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        // if one of the root is null or both of them 
        // also a basecase for the reursive call
        if (!p || !q) return p == q;
        
        // recursively call checking every single node and then pass down to left and right node
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
