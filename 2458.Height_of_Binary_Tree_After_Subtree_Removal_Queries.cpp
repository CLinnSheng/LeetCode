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
Goal: Return an array answer of size m where answer[i] is the height of the tree
after performing the ith query. Queries[i] contain the node we have to remove

Intuition: Removing a node can either maintain the height of the tree or reduce
the height of the tree. The way to find the height of a tree at a particular
node just simply take the maximum height from both its child and then +1. So we
just simply traverse to the tree to find the height when it reaches the
queres[i] node we just simply return 0 to its parent node. This will simply take
O(n) So the total time complexity will be O(n*m) We can actually optimize it by
preprocessing the tree. Having 3 arrays: 1 array store the height of each node.
1 array store the level of each node
1 array that store the 2 maximum height at that level (because if the node get
remove has the maximum height then we just simply get the 2nd highest) This
greatly reduce the time complexity to O(n + m) Space Complexity: O(n)
*/
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> treeQueries(TreeNode *root, std::vector<int> &queries) {
    int n{100001}; // nodes start from 1 to 100,000
    std::vector<int> node_height(n, 0);
    std::vector<int> node_level(n, -1);
    std::vector<std::pair<int, int>> top2_maxHeight(n, {0, 0});

    std::function<int(TreeNode *, const int)> preprocessing =
        [&](TreeNode *node, const int currLevel) {
          if (!node)
            return 0;

          int currHeight =
              1 + std::max(preprocessing(node->left, currLevel + 1),
                           preprocessing(node->right, currLevel + 1));

          node_height[node->val] = currHeight;
          node_level[node->val] = currLevel;

          if (currHeight > top2_maxHeight[currLevel].first) {
            top2_maxHeight[currLevel].second = top2_maxHeight[currLevel].first;
            top2_maxHeight[currLevel].first = currHeight;
          } else if (currHeight > top2_maxHeight[currLevel].second)
            top2_maxHeight[currLevel].second = currHeight;

          return currHeight;
        };

    preprocessing(root, 0);

    std::vector<int> ans;

    for (const auto &querie : queries) {
      int nodeHeight{node_height[querie]};
      int nodeLevel{node_level[querie]};

      int maxHeight{top2_maxHeight[nodeLevel].first == nodeHeight
                        ? top2_maxHeight[nodeLevel].second
                        : top2_maxHeight[nodeLevel].first};

      ans.emplace_back(maxHeight + nodeLevel - 1);
    }

    return std::move(ans);
  }
};
