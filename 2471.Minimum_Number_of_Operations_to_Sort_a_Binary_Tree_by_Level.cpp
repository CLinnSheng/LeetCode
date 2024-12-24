#include <algorithm>
#include <deque>
#include <functional>
#include <unordered_map>
#include <vector>

/*
 * Goal: Return the minimum opertaions needed to make values at each level sorted in ascending order
 * Operation: Choose any 2 nodes at the same level and swap their values
 *
 *
 * Intuition:
 * We dont really need to swap the 2 nodes, just need to find out how many swap we needed to make the level in
 * increasing order. Since we need to swap the nodes, how do we can always keep track which values at which index??
 * Here, we can make use of hash data structure by mapping a value into an index
 * For traversing the tree, we can use bfs for simplicity
 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 * */

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
    int minimumOperations(TreeNode *root)
    {
        int answer{};

        std::deque<TreeNode *> queue;
        queue.emplace_back(root);

        std::function<int(std::vector<int>)> count_operations = [&](std::vector<int> levels) {
            std::vector<int> sorted_levels(levels.begin(), levels.end());
            // O(logn)
            std::sort(sorted_levels.begin(), sorted_levels.end());

            // hash data structure for mapping index
            std::unordered_map<int, int> mapping_index;

            for (int i{}; i < levels.size(); i++)
                mapping_index[levels[i]] = i;

            int operations{};

            // performs swapping operations
            for (int i{}; i < levels.size(); i++)
            {
                // checking whether does it in sorted or not
                if (levels[i] == sorted_levels[i])
                    continue;

                operations++;
                // get the index of the sorted numbers
                int values_index{mapping_index[sorted_levels[i]]};

                // perform the swapping
                int temp = levels[values_index];
                levels[values_index] = levels[i];
                levels[i] = temp;

                // update the updated index
                mapping_index[levels[i]] = i;
                mapping_index[levels[values_index]] = values_index;
            }
            return operations;
        };

        // O(n)
        while (!queue.empty())
        {
            int n(queue.size());
            // arrays for storing the nodes at each level
            std::vector<int> level;
            while (n)
            {
                auto node{queue.front()};
                queue.pop_front();
                level.emplace_back(node->val);

                if (node->left)
                    queue.emplace_back(node->left);
                if (node->right)
                    queue.emplace_back(node->right);

                n--;
            }
            // O(lgn)
            answer += count_operations(level);
        }
        return answer;
    }
};
