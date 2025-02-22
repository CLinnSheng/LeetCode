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

#include <cctype>
#include <string>
#include <string_view>
using std::string;

/*
 * Each node in this traversal, output D dashes (D - Depth of the node), then output the value.
 * Goal: Recover the tree
 *
 * Intuition:
 * The traversal is preorder But how do we determine that like the child gonna be lhs or rhs if it only has 1 child
 * The question has explicitly mentioned that the child guaranteed to be the left child when u have 1 child
 * Theres must be some purpose of the dash and the number of dash for each val.
 * We can use the number of dash to determine whether this node should put at which level
 * So we can simply just use dfs because since the given traversal is preorder, so it will go as deep as possible on 1
 * path and return back when it reach the desire depth
 * Time Complexity: O(n)
 * */
class Solution
{
  private:
    TreeNode *dfs(const std::string &str, const int &depth, int &index)
    {
        // base case
        if (index >= str.length())
            return nullptr;

        // check the current depth first
        int nDash{};
        while (index + nDash < str.length() && str[index + nDash] == '-')
            nDash++;

        // check whether this value is at correct depth or not
        if (depth != nDash)
            return nullptr;

        // correct, then extract the value
        index += nDash;
        int val{};
        while (index < str.length() && isdigit(str[index]))
        {
            val = val * 10 + int(str[index] - '0');
            index++;
        }

        TreeNode *node = new TreeNode(val);

        node->left = dfs(str, depth + 1, index);
        node->right = dfs(str, depth + 1, index);

        return node;
    }

  public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        int index{};
        return dfs(traversal, 0, index);
    }
};
