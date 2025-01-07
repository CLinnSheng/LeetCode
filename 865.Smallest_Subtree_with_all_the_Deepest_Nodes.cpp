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
 * Goal: Return the smallest subtree such that it contains all the deepest nodes in the original tree.
 *
 * Intuition:
 * Find the deepest nodes --> Depth
 * Use dfs to traverse the graph & find the maximum depth
 * how do we know we at the subtree?
 * We can tell by checking the detph of the left subtree & right subtree are both equal to 1 or not.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * */
#include <algorithm>
class Solution
{
  private:
    int maxDepth{-1};
    TreeNode *answerNode{nullptr};

  public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        helper(root, 0);
        return answerNode;
    }

    // this helper function help to compute the depth of each node through dfs
    int helper(TreeNode *node, int depth)
    {
        if (!node)
            return depth;

        int left_depth{helper(node->left, depth + 1)};
        int right_depth{helper(node->right, depth + 1)};

        // if the left & right subtree has the same depth
        // this subtree might be the deepest
        if (left_depth == right_depth && left_depth >= maxDepth)
        {
            answerNode = node;
            maxDepth = left_depth;
        }
        return std::max(left_depth, right_depth);
    }
};
