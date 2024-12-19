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
Given the root of a binary tree, return the level order traversal of its nodes'
values. (i.e., from left to right, level by level).

Constraint: level by level
Intuition: Left to right --> Inorder traversal
Can use queue data structure.
How to make sure is from the same level?
    Every time we insert the child node we keep track of the size, so the size
indicate the number of nodes in the next level Time Complexity: O(n) traverse
every single node Space Complexity: O(n)
*/

#include <deque>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // Handling special case
    if (!root)
      return {};

    std::vector<std::vector<int>> ans;
    std::deque<TreeNode *> queue;
    queue.emplace_back(root);

    while (!queue.empty()) {
      int curr_level = queue.size();
      std::vector<int> level_nodes;

      while (curr_level > 0) {
        auto front = queue.front();
        queue.pop_front();
        level_nodes.emplace_back(front->val);

        if (front->left)
          queue.emplace_back(front->left);
        if (front->right)
          queue.emplace_back(front->right);

        curr_level--;
      }
      ans.emplace_back(level_nodes);
    }
    return ans;
  }
};
