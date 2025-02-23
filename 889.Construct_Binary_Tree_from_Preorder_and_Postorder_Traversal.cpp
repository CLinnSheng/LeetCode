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

#include <functional>
#include <unordered_map>
#include <vector>
using std::vector;

/*
 * Goal: Build a tree from preorder & postorder traversal
 *
 * Intuition:
 * Know the purpose of giving preorder and postorder.
 * That means need to get information from these 2 traversal to build the tree.
 * Characteristics:
 * 1. Preorder
 *  - Top down
 *  - Root Come first
 *  - Then the node come after the root will be the left child
 *
 * 2. Postorder
 *  - Use the information from preorder, we can deduce that every element come before the node will
 *  be belong to the subtree with this node as the root.
 *  - Bottom up
 *
 *  We can recursively build up the tree by dividing into subproblem where each node has a specific range in the
 * preorder & postorder to build the subtree Time Complexity: O(n)
 * */
class Solution
{
  public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n(preorder.size());
        std::unordered_map<int, int> postMap;
        for (int i{}; i < n; i++)
            postMap[postorder[i]] = i;

        std::function<TreeNode *(const int &, const int &, const int &, const int &)> helper =
            [&](const int &startPre, const int &endPre, const int &startPos, const int &endPos) {
                // base cases
                if (startPre > endPre || startPos > endPos)
                    return (TreeNode *)nullptr;

                TreeNode *node = new TreeNode(preorder[startPre]);

                // if same index means the subtree only has size of 1 and thus has no child
                if (startPre != endPre)
                {
                    // get the left child of the root, we can straight away deduce from the preorder traversal
                    int leftChild{preorder[startPre + 1]};

                    // get the index of the leftChild in the postorder
                    int leftIndex{postMap[leftChild]};

                    // get the size of the subtree through postorder traversal, because according to postorder
                    // the child will come first and then at the end only will be the root
                    int leftSubtreeSize{leftIndex - startPos + 1};

                    // recursively build left & right subtree
                    node->left = helper(startPre + 1, startPre + leftSubtreeSize, startPos, leftIndex);
                    node->right = helper(startPre + 1 + leftSubtreeSize, endPre, leftIndex + 1, endPos - 1);
                }
                return node;
            };
        return helper(0, n - 1, 0, n - 1);
    }
};
