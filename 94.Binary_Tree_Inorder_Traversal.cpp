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
#include <functional>
#include <vector>
class Solution
{
  public:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::function<void(std::vector<int> &, TreeNode *)> helper = [&](std::vector<int> &ans, TreeNode *node) {
            if (node == nullptr)
            {
                return;
            }

            helper(ans, node->left);
            ans.push_back(node->val);
            helper(ans, node->right);
        };

        std::vector<int> ans;
        helper(ans, root);

        return ans;
    }
};
