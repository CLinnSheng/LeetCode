/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
 * Finding the maximum path sum
 * So is not compulsory to include all the nodes.
 * But it must not be empty path
 * There are 3 cases
 * 1 is included the root and then both the left and subtree
 * 2 is just one path from one of the subtree
 * 3 is just root down to any intermediate or leaf node
 * */

#include <algorithm>
class Solution
{
  private:
    int maximumSubTreePath(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int left = node->val + maximumSubTreePath(node->left);
        int right = node->val + maximumSubTreePath(node->right);

        // Get the maximum path
        int pathSum = std::max(left, right);

        // Be greedy dont include those less than 0
        return std::max(0, pathSum);
    }

    void dfs(int &ans, TreeNode *node)
    {
        // Base Case
        if (node == nullptr)
        {
            return;
        }

        int leftSub = maximumSubTreePath(node->left);
        int rightSub = maximumSubTreePath(node->right);

        ans = std::max(ans, node->val + leftSub + rightSub);

        // Then try again at the left & right subtree because it is not neccessarily to start with this node
        dfs(ans, node->left);
        dfs(ans, node->right);
    }

  public:
    int maxPathSum(TreeNode *root)
    {
        int ans{INT_MIN};

        dfs(ans, root);

        return ans;
    }
};
