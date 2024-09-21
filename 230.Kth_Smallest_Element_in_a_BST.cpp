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
 * Goal: Reeturn the kth smallest element in BST
 *
 * Intuition: Since return kth smallest element and the tree is a BST. Utilize
 * BST property where the smallest is in the most left So we just have to go all
 * the way down to the smallest node and search for kth smallest
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) Because we searching all the node
 * */
#include <algorithm>
#include <ios>
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (root == nullptr)
      return -1;

    std::deque<TreeNode *> stack;
    stack.emplace_back(root);
    root = root->left;

    while (!stack.empty() || root) {

      while (root) {
        stack.emplace_back(root);
        root = root->left;
      }

      root = stack.back();
      stack.pop_back();

      if (--k == 0)
        return root->val;

      root = root->right;
    }

    return -1;
  }
};
