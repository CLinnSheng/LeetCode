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

#include <cstdlib>
#include <functional>
#include <utility>
class Solution
{
    std::pair<bool, int> helper(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {true, 0};
        }

        auto left = helper(node->left);
        auto right = helper(node->right);

        return {left.first && right.first && std::abs(left.second - right.second) <= 1,
                1 + std::max(left.second, right.second)};
    }

  public:
    bool isBalanced(TreeNode *root)
    {
        // A tree is only balanced if the height differ for node at any level is differ not more than 1
        // So we need to compare  level by level
        // Information we need is just the level at each node, and whether the level the node at is balanced or not
        // Can do it recursively from the bottom
        return helper(root).first;
    }
};
