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
 * Path is a sequence of nodes where each pair of adjacent nodes in the sequence has an
 * edge connecting them. A node can be appear only once in the sequence.
 * IMPORTANT: Not compulsory to pass through the root.
 * Goal: Find the maximum path sum
 *
 * Intuition:
 * There is no constraint on how to form the path as long as the node traverse once can already.
 * And another important thing is is not ncessarily to include the root node.
 * So we will basically compute the sum at avery node, which means we treat every node as the root node.
 * So we can solve it through recursively to compute the sum at evey single node.
 * Then another helper function to compute the maximum path sum for the left and right subtree
 */
#include <algorithm>
#include <climits>
class Solution
{
  private:
    int answer{INT_MIN};

    int helperGetSubtreeMaxPath(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int left = helperGetSubtreeMaxPath(node->left);
        int right = helperGetSubtreeMaxPath(node->right);

        int pathSum = node->val + std::max(left, right);

        // handle edge cases where it consists all negative nodes
        return std::max(0, pathSum);
    }

    void dfs(TreeNode *node)
    {
        if (node == nullptr)
            return;

        int left = helperGetSubtreeMaxPath(node->left);
        int right = helperGetSubtreeMaxPath(node->right);

        answer = std::max(answer, node->val + left + right);

        dfs(node->left);
        dfs(node->right);
    }

  public:
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return this->answer;
    }
};
