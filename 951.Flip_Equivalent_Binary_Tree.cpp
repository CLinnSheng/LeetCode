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
 * Goal: Check whether the 2 trees are equivalent by flip equivalent
 * Intuition: Is not neccessary to flip the whole tree, you can flip at certain
 * level So at each level we will find out whether the tree is equivalent by
 * flipping or not flipping the current level. Time Complexity: even though is
 * bounded by O(2^n) but we wont try every single possiblities, the algorithm
 * will just stop  when there are not matching. So at worst will be O(n). Space
 * Complexity: Will be the recursion function stack. at worst is bounded by O(n)
 * for skewed tree or for balanced tree will be O(lgn)
 * */
#include <functional>
class Solution {
public:
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    if (!root1 || !root2)
      return root1 == root2;
    if (root1->val != root2->val)
      return false;

    // considering 2 possibilities flipping or not flipping
    return (flipEquiv(root1->left, root2->left) &&
            flipEquiv(root1->right, root2->right)) ||
           (flipEquiv(root1->left, root2->right) &&
            flipEquiv(root1->right, root2->left));
  }
};
