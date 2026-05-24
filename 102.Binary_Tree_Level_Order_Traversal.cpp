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
 * Level Tree Order Traversal
 * So from left to right --> From this observation we can use FIFO which is queue
 * For every  level we need to track its count as well, so that we know when to stop for this level
 * as we will keep inserting new node in the queue
 * Time Complexity: O(n)
 * */
#include <deque>
#include <vector>
class Solution
{
  public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        // Base Case
        if (root == nullptr)
        {
            return {};
        }

        std::deque<TreeNode *> queue;
        queue.push_back(root);
        std::vector<std::vector<int>> ans{};

        while (!queue.empty())
        {
            std::vector<int> temp{};
            int cnt = queue.size();

            while (cnt)
            {
                TreeNode *node = queue.front();
                queue.pop_front();

                temp.push_back(node->val);

                if (node->left)
                {
                    queue.push_back(node->left);
                }
                if (node->right)
                {
                    queue.push_back(node->right);
                }

                cnt--;
            }

            ans.push_back(temp);
        }
        return ans;
    }
};
