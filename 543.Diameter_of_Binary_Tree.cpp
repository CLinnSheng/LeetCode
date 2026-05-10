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
class Solution
{
  public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        // Finding the longest diameter  which is the connecting nodes of the tree
        // So there is either 2 possible path, 1 will be connecting the nodes from both sides
        // Another possible path just simply be 1 path from the root to the leaf
        // So we can search through the tree from the leaf through recursive and get the maximum diameter at every
        // single node
        int ans{};

        std::function<int(TreeNode *)> helper = [&](TreeNode *node) {
            if (node == nullptr)
            {
                return 0;
            }

            int left = helper(node->left);
            int right = helper(node->right);

            ans = std::max(ans, left + right);

            // Return the deeper path
            return 1 + std::max(left, right);
        };

        helper(root);
        return ans;
    }
};
