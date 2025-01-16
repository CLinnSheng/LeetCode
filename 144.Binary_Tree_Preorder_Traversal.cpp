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
        std::vector<int> answer;
        std::function<void(TreeNode *)> dfs = [&](TreeNode *node) {
            if (!node)
                return;

            answer.emplace_back(node->val);
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return answer;
    }
};
