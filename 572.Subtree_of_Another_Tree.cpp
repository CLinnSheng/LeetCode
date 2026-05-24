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
 * Need to check whether subtree exist or not
 * then mean we only check when we find the root of the subtree
 * */
class Solution
{
    bool sameTree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr || subRoot == nullptr)
        {
            return root == subRoot;
        }

        return root->val == subRoot->val && sameTree(root->left, subRoot->left) &&
               sameTree(root->right, subRoot->right);
    }

  public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        // Base Case
        if (root == nullptr)
        {
            return false;
        }

        // Check have we found the root node of the subRoot
        if (root->val == subRoot->val && sameTree(root, subRoot))
        {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
