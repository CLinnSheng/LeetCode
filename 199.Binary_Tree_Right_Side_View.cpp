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
 * We can use level order traversal then only push into the ans vector
 * when is the last node in the level
 * */
#include <deque>
#include <vector>
class Solution
{
  public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        std::deque<TreeNode *> queue;
        queue.push_back(root);
        std::vector<int> ans;

        while (!queue.empty())
        {
            int cnt = queue.size();

            while (cnt)
            {
                TreeNode *node = queue.front();
                queue.pop_front();

                if (node->left)
                {
                    queue.push_back(node->left);
                }
                if (node->right)
                {
                    queue.push_back(node->right);
                }

                if (--cnt == 0)
                {
                    ans.push_back(node->val);
                }
            }
        }
        return ans;
    }
};
