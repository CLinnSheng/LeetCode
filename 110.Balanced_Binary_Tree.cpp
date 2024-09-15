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
Goal: Check whether the tree is balanced or not 
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Intuition: At every node compare its left and right subtree height if one of the node violates then the whole tree is not balance

Time Complexity: O(n lg n) Traverse single node and calling getHeight (lgn)
Space Complexity: O(lgN) becasue of recursive call

Another way to reduce time complexity is calculate the height and check balance in a single pass which reduce it to O(N)
*/
#include <algorithm>
#include <cstdlib>
#include <utility>
class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        return checkBalance(root).first;
    }
    
    std::pair<bool, int> checkBalance(TreeNode* root)
    {
        if (root == nullptr) return {true, 0};
        
        auto left = checkBalance(root->left);
        auto right = checkBalance(root->right);
        
        return {left.first && right.first && std::abs(left.second - right.second) <= 1, 1 + std::max(left.second, right.second)};
    }
    
};