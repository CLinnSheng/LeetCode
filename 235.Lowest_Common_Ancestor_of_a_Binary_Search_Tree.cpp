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
 * Finding the lowest common ancestor between 2 nodes.
 * Note: An ancestor is allowed to be a descedent of itself
 *
 * A few thing to take note
 * First the tree is a binary search tree which we can make use of its property
 * We can use recursive approach where we check from the top instead of the bottom
 * Then the way to check whether we found the node through comparing the current node with p & q
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Base Case
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }

        return nullptr;
    }
};
