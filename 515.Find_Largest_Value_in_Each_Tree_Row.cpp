#include <algorithm>
#include <climits>
#include <deque>
#include <vector>

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
 * Goal: Return an array of the largest value ion each row of the tree
 * Intuition: BFS to traverse the tree and then use a maxHeap to get the maximum values on each level of the tree
 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 *
 * Actually theres a better way instead of using heap, we can actually just use a variable to hold the maximum and keep
 * checking it
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    std::vector<int> largestValues(TreeNode *root)
    {
        std::vector<int> answer;
        std::deque<TreeNode *> queue;

        if (root == nullptr)
            return {};
        queue.emplace_back(root);

        while (!queue.empty())
        {
            int max{INT_MIN};
            int size(queue.size());

            while (size--)
            {
                auto currNode{queue.front()};
                queue.pop_front();
                max = std::max(max, currNode->val);

                if (currNode->left)
                    queue.emplace_back(currNode->left);
                if (currNode->right)
                    queue.emplace_back(currNode->right);
            }

            answer.emplace_back(max);
        }
        return answer;
    }
};
