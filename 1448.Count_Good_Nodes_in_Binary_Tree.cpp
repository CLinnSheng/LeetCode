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
 * Goal: Return the number of good nodes
 * Good node: A node X is a good node if in the path from root to X there are no
 * nodes with a value greater than X.
 *
 * Intuition:
 * Use dfs or recursive and pass the current maximum value so that we know that whether the node we visited is it the
 * maximum or not in order to determine whether is it a good nodes or not. A root node is always a good node
 *
 * Time Complexity: O(n)
 */
#include <functional>
class Solution
{
  public:
    int goodNodes(TreeNode *root)
    {
        int answer{};

        std::function<void(TreeNode *, int)> helper = [&](TreeNode *node, int maximumVal) {
            if (node == nullptr)
                return;

            if (node->val >= maximumVal)
            {
                answer++;
                maximumVal = node->val;
            }

            helper(node->left, maximumVal);
            helper(node->right, maximumVal);
        };

        helper(root, root->val);
        return answer;
    }
};
