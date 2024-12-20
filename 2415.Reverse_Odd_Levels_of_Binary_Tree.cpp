#include <deque>

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
 * Given a root, reverse the node values at each odd level of tree
 *
 * Intuition:
 * Use BFS to traverse the tree and then at odd level reverse the tree
 * Use a deque data structure so that we can easily access the element to flip
 * the order
 *
 * Time Complexity: O(n) where n is the number of nodes
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        std::deque<TreeNode *> queue;
        queue.emplace_back(root);
        int level{};

        while (!queue.empty())
        {
            int size(queue.size());

            // reversing at the odd level
            if (level & 1)
            {
                int l{}, r{size - 1};
                while (l < r)
                {
                    int x{queue[l]->val};
                    int y{queue[r]->val};
                    int temp{x};

                    queue[l]->val = y;
                    queue[r]->val = temp;

                    l++;
                    r--;
                }
            }

            while (size)
            {
                auto current_node{queue.front()};
                queue.pop_front();

                if (current_node->left)
                    queue.emplace_back(current_node->left);
                if (current_node->right)
                    queue.emplace_back(current_node->right);

                size--;
            }
            level++;
        }
        return root;
    }
};
