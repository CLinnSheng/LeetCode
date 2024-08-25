#include <bits/stdc++.h>
using namespace std;
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
 PostOrder Traversal: Left -> Right -> Parent
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<int> ans;
        helper(root, ans);
        
        return ans;
    }
    
    void helper(TreeNode* root, vector<int>& ans) {
        
        if (!root)
            return;
            
        helper(root->left, ans);
        helper(root->right, ans);
        
        ans.emplace_back(root->val);
    }
    
};