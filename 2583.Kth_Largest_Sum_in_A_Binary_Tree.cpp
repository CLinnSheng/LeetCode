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
 * Goal: Return the kth largest level sum in the tree
 * Constraint: k might be greater than the depth of the tree.
 *
 * Intuition: Use bfs to traverse the tree and then push into the heap
 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(lgn)
 * */
#include <deque>
#include <functional>
#include <queue>
#include <vector>
class Solution {
public:
  long long kthLargestLevelSum(TreeNode *root, int k) {

    std::deque<TreeNode *> queue;
    std::priority_queue<long long, std::vector<long long>,
                        std::greater<long long>>
        minHeap;

    queue.emplace_back(root);
    while (!queue.empty()) {
      int currSize{queue.size()};
      int currSum{};

      for (int i{}; i < currSize; i++) {
        auto temp = queue.front();
        queue.pop_front();

        currSum += temp->val;
        if (temp->left)
          queue.emplace_back(temp->left);
        if (temp->right)
          queue.emplace_back(temp->right);
      }

      minHeap.emplace(currSum);
    }

    if (k > minHeap.size())
      return -1;
    while (k < minHeap.size())
      minHeap.pop();

    return minHeap.top();
  }
};
