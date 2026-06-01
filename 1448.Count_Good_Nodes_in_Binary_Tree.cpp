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
 * A node, x is consider good if it doenst contain any nodes from the root to the node x has value greater than its
 *
 * Intuition:
 * So tree can be either solve through bfs/dfs
 * So over here both works. Key information that we need to pass down is the current maximum value from the node, so
 * that we can compare to it
 *
 * So we use dfs here and simply just travers the tree
 * Time Complexity: O(n)
 * Space Complexity: O(h) where h is the height of the tree
 * */
class Solution
{
  public:
    int goodNodes(TreeNode *root)
    {
        // Root node itself consider a good node
        int cnt{1};

        auto dfs = [&](auto &self, TreeNode *node, int currMax) -> void {
            if (node == nullptr)
            {
                return;
            }

            if (node->val >= currMax)
            {
                currMax = node->val;
                cnt++;
            }

            // Traverse both side
            self(self, node->left, currMax);
            self(self, node->right, currMax);
        };

        dfs(dfs, root->left, root->val);
        dfs(dfs, root->right, root->val);

        return cnt;
    }
};
