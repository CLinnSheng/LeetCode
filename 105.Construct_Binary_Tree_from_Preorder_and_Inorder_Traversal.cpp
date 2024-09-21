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
Given 2 array, 1 is inorder and another is preorder
Preorder: We get the information of the first node,
for example the first node is the root node and then the second node is another
root node Inorder: We can get to know the left and right child of the rood node
given that if we know the root node if root node at index 2 then left node will
be 1 and right node will be index 3 & it also gives information for the size of
the whole subtree

Intuition: After construct the root node from preorder then find its left and
right child from inorder (checking left and right)

Time Complexity: O(n)
Space Complexity: O(lgn)
*/
class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // Use a hash to store the index of the preorder number
    std::unordered_map<int, int> map;
    for (int i = 0; i < inorder.size(); i++)
      map[inorder[i]] = i;
    int index = 0;
    return helper(map, preorder, inorder, index, 0, preorder.size() - 1);
  }

  TreeNode *helper(std::unordered_map<int, int> &map,
                   std::vector<int> &preorder, std::vector<int> &inorder,
                   int &index, int start, int end) {

    if (start > end)
      return nullptr;

    TreeNode *node = new TreeNode(preorder[index++]);

    int mid = map[node->val];
    node->left = helper(map, preorder, inorder, index, start, mid - 1);
    node->right = helper(map, preorder, inorder, index, mid + 1, end);

    return node;
  };
};
