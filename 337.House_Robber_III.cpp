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
 *
 * Only 1 entrace which is the root
 * If 2 directly-linked houses were broken then alarm will be ring
 * So we cannot have 2 directly-linked nodes
 *
 * So basically is kind of like dp problem, because at each node we can choose to rob or not
 * So brute force will take O(2^n)
 * We can further optimize it by using caching becasuse some nodes were visited more than once
 * Time Complexity: O(n)
 * Spaec Complexity: O(n)
 */
#include <unordered_map>
class Solution
{
    // Cache/Memoziation/Dp
    std::unordered_map<TreeNode *, int> cache;

  public:
    int rob(TreeNode *root)
    {

        // Basecase
        if (root == nullptr)
        {
            return 0;
        }

        // Check Cache
        if (cache.find(root) != cache.end())
        {
            return cache[root];
        }

        int ans = root->val;

        // 2 Cases: Either choose the root node or the child node
        // First Case: Root Node
        if (root->left)
        {
            ans += rob(root->left->left) + rob(root->left->right);
        }

        if (root->right)
        {
            ans += rob(root->right->left) + rob(root->right->right);
        }

        // 2nd Case: Child node
        return cache[root] = std::max(ans, rob(root->left) + rob(root->right));
    }
};
