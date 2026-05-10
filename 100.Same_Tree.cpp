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
class Solution
{
  public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // Checking whether the 2 tree are the same or node
        // Checking every single nodes
        // Do it recursively from the bottom

        if (p == nullptr || q == nullptr)
        {
            return p == q;
        }

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
