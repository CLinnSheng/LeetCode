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
 * Goal: Replace the value of each node in the tree with sum of all its cousins'
 * values. Two nodes of a binary tree are cousins if they have the same depth
 * with diferent parents.
 *
 * Intuition: The node of every value will be the sum of the current level minus
 * itself and its sibilings which is connected to the same parents
 * So we gonna traverse 2 times (either bfs or dfs)
 * first bfs will be getting the levelSum
 * Then the second bfs will be changing the value, this will be a little tricky
 * on how to change it. So when we traverse every single node, we will be
 * passing the sibilings sum to it. So in the end the value will just simply be
 * levelSum - sibilingsSum
 *
 * Time Complexity: O(n) traversing every single node
 * Space Complexity: O(n)
 * */
#include <deque>
#include <utility>
class Solution {
public:
  TreeNode *replaceValueInTree(TreeNode *root) {

    std::deque<TreeNode *> queue;
    std::vector<int> levelSum;

    queue.emplace_back(root);

    while (!queue.empty()) {
      auto currSize(queue.size());
      int currSum{};

      for (int i{}; i < currSize; i++) {
        auto currNode = queue.front();
        queue.pop_front();
        currSum += currNode->val;
        if (currNode->left)
          queue.emplace_back(currNode->left);
        if (currNode->right)
          queue.emplace_back(currNode->right);
      }

      levelSum.emplace_back(currSum);
    }

    std::deque<std::pair<TreeNode *, int>> queue_sibilingSums;
    queue_sibilingSums.emplace_back(std::make_pair(root, root->val));
    int level{};

    while (!queue_sibilingSums.empty()) {
      auto currSize{queue_sibilingSums.size()};

      for (int i{}; i < currSize; i++) {
        auto [currNode, sibilingsSum] = queue_sibilingSums.front();
        queue_sibilingSums.pop_front();

        currNode->val = levelSum[level] - sibilingsSum;

        int childSum{};

        if (currNode->right)
          childSum += currNode->right->val;
        if (currNode->left)
          childSum += currNode->left->val;

        if (currNode->right)
          queue_sibilingSums.emplace_back(
              std::make_pair(currNode->right, childSum));
        if (currNode->left)
          queue_sibilingSums.emplace_back(
              std::make_pair(currNode->left, childSum));
      }

      level++;
    }

    return root;
  }
};
