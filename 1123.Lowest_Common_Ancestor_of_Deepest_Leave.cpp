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
 * Goal: Return the lowest common ancestor of its deepest leaves.
 *
 * Intuition:
 * Tree Problem can be solve using dfs or bfs.
 * Both dfs & bfs can solve but dfs implementation is much more easier.
 * Bfs we simply just need to do the search until last row.
 * Then search up from the bottom to find the common ancestor.
 * But this will be kinda like brute force if search through all the leaf nodes.
 * Actually we only need to search from the most left and most right leaf because if we have tree comes from different
 * subtree, what really matters is just the most left & right leaf.
 *
 * How about dfs?
 * PostOrder, Inorder, Preorder
 * We can split the problem into subproblem, where we find the lowest common ancestor from the leaf first then go all.
 * So start from the leaf, the leaf itself is the lowest common ancestor, then also the same for its sibling of the same
 * parent. Then we pass these information up to the parent. Then the parent will get to decide which node is the lowest
 * common ancestor based on the information given. Since both have the same left & right depth therefore, the parent is
 * the lowest common ancestor. the way up to the root --> Bottom Up Postorder will be more appropriate, because we need
 * to get both the lhs & right child information about the deepest leave and pass the 1 with greater depth Time
 * Complexity: O(n)
 * */
#include <utility>
class Solution
{
  private:
    std::pair<TreeNode *, int> dfs(TreeNode *root)
    {
        // base case
        if (!root)
        {
            return {nullptr, 1};
        }

        // information of both child
        auto left{dfs(root->left)}, right{dfs(root->right)};

        if (left.second > right.second)
            return {left.first, left.second + 1};
        else if (left.second < right.second)
            return {right.first, right.second + 1};

        return {root, left.second + 1};
    }

  public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        return dfs(root).first;
    }
};
