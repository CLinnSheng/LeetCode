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
Goal: Check whether subRoot is a subroot of root
Intuition: First we need to find the root of subRoot in side the root first then we can only do traverse the tree to do checking
Time Complexity: O(n*m) in worst case lets say have the same root val
Space Complexity: O(lgnm)
*/
#include <deque>
#include <iostream>
#include <ios>

class Solution 
{
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        // i. Stack approach
        // std::deque<TreeNode*> stack;
        // stack.push_back(root);
        // bool ans = false;

        // while (!stack.empty())
        // {
        //     auto temp = stack.back();
        //     stack.pop_back();
            
        //     if (temp->val == subRoot->val) ans = ans || helper(temp, subRoot);
            
        //     if (temp->right) stack.push_back(temp->right);
        //     if (temp->left) stack.push_back(temp->left);
        // }
        
        // return ans;

        // ii. Recursive approach
        if (!subRoot) return true; // empty subtree means is a subrtree of tree
        if (!root) return false; // when root traverse down to nullptr means we could nt find the subtree in the main tree
        if (subRoot->val == root->val && helper(root, subRoot)) return true;

        // Continue down to search
        return isSubtree(root->left, subRoot) ||  isSubtree(root->right, subRoot);
    }
    
    bool helper(TreeNode* root, TreeNode* subRoot)
    {
        // Base Case
        if (!root || !subRoot) return root == subRoot;

        return root->val == subRoot->val && helper(root->left, subRoot->left) && helper(root->right, subRoot->right);
    }
};