#include <functional>
#include <vector>
using std::vector;

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> ans;

        std::function<void(std::vector<int> &, TreeNode *)> helper = [&](std::vector<int> &ans, TreeNode *node) {
            if (node == nullptr)
            {
                return;
            }

            ans.push_back(node->val);
            helper(ans, node->left);
            helper(ans, node->right);
        };

        helper(ans, root);
        return ans;
    }
};
