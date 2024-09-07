/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
Goal: Check whether all the elements in the linked list starting from the head coresspond to some downward path
connected in the binary tree

Intuition: Use dfs to recursively find the subpath only if it match or else we try to dfs with the child nodes
Time Complexity: O(mn) Worst Case: need to check every single nodes in the tree and each node we need to traverse the linked list 
so ended up in M*N;
Spaec Complexity: O(m + n) 
 */
class Solution 
{
public:
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if (!root) return false;
        return helper_dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool helper_dfs(ListNode* head, TreeNode* root)
    {
        // reach the end of linked list
        if (!head) return true;

        // reach root of the tree
        if (!root) return false;

        // if doesnt matched we dont want to continue
        // return back and try with the child nodes
        if (root->val != head->val) return false;

        return helper_dfs(head->next, root->left) || helper_dfs(head->next, root->right);
    }

    
};