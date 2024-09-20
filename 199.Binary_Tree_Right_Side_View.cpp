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
Imagine standing on the right of it return the values of the nodes from your
side from top to bottom Intuition: we can use stack/queue data structure, so at
every level we only add the first element in front of the data structure to our
list and then dont consider about others, just add the child of every single
node to it. So, how do we determine how many node we gonna remove every single
time, we can tell by the size of the data structure

Time Complexity: O(n) we just basically traverse every node
Space Complexity: O(n)
*/
#include <deque>
#include <ios>
#include <iostream>
class Solution {
public:
  std::vector<int> rightSideView(TreeNode *root) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (!root)
      return {};

    std::deque<TreeNode *> stack;
    std::vector<int> ans;

    stack.emplace_back(root);

    while (!stack.empty()) {

      int n_nodes = stack.size();
      std::vector<int> current_lvl;

      while (n_nodes > 0) {

        auto top = stack.front();
        stack.pop_front();

        if (top->left)
          stack.emplace_back(top->left);
        if (top->right)
          stack.emplace_back(top->right);

        n_nodes--;
        current_lvl.emplace_back(top->val);
      }

      ans.emplace_back(current_lvl.back());
    }

    return ans;
  }
};
