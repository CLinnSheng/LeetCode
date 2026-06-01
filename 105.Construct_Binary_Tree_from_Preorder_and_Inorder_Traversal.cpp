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
 * Construct a tree based on Preorder Traversal & Inorder Traversal
 * So the key will be make use of the property of preorder and inorder
 * Preorder:
 * - push
 * - left
 * - right
 * So at any index within the preorder array, the node itself is the root of the subtree
 *
 * Inorder
 * - left
 * - push
 * - right
 * So at any index we can know the node of its left child & right child
 * for instance for root at index 2 -> Index 1 will be the left child and index 3 will be the right child
 *
 * So what we can do is create the root node of a subtree from preorder array, then get the index of the node in the
 * inorder array. So that we can get the left & right node from the inorder array
 * We can use dfs/recursive to build the tree, since we need to create it from the array then we need to pass the index
 * and also the range we can search through
 * */
#include <unordered_map>
class Solution
{
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // Map to store the indices of the node
        std::unordered_map<int, int> mp;
        int index{};

        for (int i{}; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return helper(mp, preorder, inorder, index, 0, preorder.size() - 1);
    }

    TreeNode *helper(const std::unordered_map<int, int> &mp, std::vector<int> &preorder, std::vector<int> &inorder,
                     int &index, int start, int end)
    {
        // Base Case
        if (start > end)
        {
            return nullptr;
        }

        // Create the rood node of the subtree from preorder
        TreeNode *root = new TreeNode(preorder[index++]);

        // Get the index of this node in inorder
        // Becasue we can form the child node from inorder array
        int root_index = mp.at(root->val);

        root->left = helper(mp, preorder, inorder, index, start, root_index - 1);
        root->right = helper(mp, preorder, inorder, index, root_index + 1, end);

        return root;
    };
};
