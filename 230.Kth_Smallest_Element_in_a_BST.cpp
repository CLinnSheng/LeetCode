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
 * Finding the kth smallest node in a BST tree
 * We need to make use of BST property to traverse the tree.
 * Since we need to find the kth smallest, we need to store all the nodes we previously traversed and start
 * counting from the smallest node
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h) --> h - Height of the tree
 * */
#include <deque>
class Solution
{
  public:
    int kthSmallest(TreeNode *root, int k)
    {
        // Store in a queue
        std::deque<TreeNode *> queue;

        while (!queue.empty() || root)
        {
            // Keep Traverse to the left
            while (root)
            {
                queue.emplace_back(root);
                root = root->left;
            }

            // Get the smallest node
            root = queue.back();
            queue.pop_back();

            if (--k == 0)
            {
                return root->val;
            }

            // Go the right subtree to continue to find the next smallest
            root = root->right;
        }

        return -1;
    }
};
