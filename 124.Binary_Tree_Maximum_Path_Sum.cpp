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
Goal: Find the maximum path
Intuition: At every compute the sum from the its maximum distance from left node
+ right node We must decide which path we want to choose at each node either
left or right but dont forget to compute the maximum sum at the current node to
check whether this path has the maximum length Then keep updating the maximum
path Time Complexity: O(n) Space Complexity: O(lgn)
*/
class Solution {
public:
  int maxPathSum(TreeNode *root) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int ans = INT_MIN;

    helper(root, ans);

    return ans;
  }

  int helper(TreeNode *node, int &ans) {

    if (node == nullptr)
      return 0;

    int left_sum = helper(node->left, ans);
    int right_sum = helper(node->right, ans);

    int temp_choosing =
        std::max(std::max(left_sum, right_sum) + node->val, node->val);
    int sum = std::max(temp_choosing, node->val + left_sum + right_sum);
    ans = std::max(ans, sum);

    return temp_choosing;
  }
};
