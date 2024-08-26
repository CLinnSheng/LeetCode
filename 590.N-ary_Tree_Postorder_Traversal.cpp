#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*
Goal: Return it in postorder Traversal
Constraint: Not a binary Tree
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
     
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
                
        if (root->children.size() == 0)
            return { };
    
        vector<int> ans;
        helper(root, ans);
        
        return ans;
    }
    
    void helper(Node* root, vector<int>& ans) {
        
        if (!root)
            return;
    
        for (const auto& child : root->children)
            helper(root, ans);
            
        ans.emplace_back(root->val); 
    }
};