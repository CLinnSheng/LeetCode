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
Goal: Find the longest path between any two nodes in the tree
Intuition: The distance between 2 nodes that go through the root node will be the largest rather than straight from root to the leave
So we will dfs each root node from the left and right and sum it up and find the total distance from the max left and max right on each node (treat each node as the root)

Time Complexity; O(n)
Space Complexity: O(lgN)
*/
#include <functional>
#include <ios>
#include <iostream>
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int ans = 0;

        std::function<int(TreeNode*)> dfs = [&](TreeNode* root)
        {
            if (root == nullptr) return 0;
            
            int left = dfs(root->left);
            int right = dfs(root->right);
            
            ans = std::max(ans, left + right);

            return 1 + std::max(left, right);
        };

        dfs(root);
        return ans;
    }
};