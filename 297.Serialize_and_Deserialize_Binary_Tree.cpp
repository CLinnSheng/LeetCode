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
Goal: Serialize and deserialize the binary tree
Intuition: Serialize the binary tree through the way we traverse the tree
At here, we traverse the tree through preorder traversal because we want to
build the tree from the top as the first node in preorder is the root node we
use a delimiter to seperate between each node in the string

For deserialize we just follow the way we traverse through the tree

Time Complexity: O(n)
Space Complexity: O(lgn)
*/
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    std::stringstream s;
    dfs_serialize(root, s);
    return s.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    std::stringstream input(data);
    return dfs_deserialize(input);
  }

  // Store it preorderly because is easier to track which nodes is leaf node
  // the last node that company by two nullptr will be the leaf node
  void dfs_serialize(TreeNode *root, std::stringstream &s) {
    if (!root)
      s << "N" << ' ';
    else {
      // for stringstream by default is seperate by whitespace, so we use
      // whitespace to seperate it
      s << root->val << ' ';
      dfs_serialize(root->left, s);
      dfs_serialize(root->right, s);
    }
  }

  TreeNode *dfs_deserialize(std::stringstream &input) {
    std::string current_val;
    input >> current_val;
    if (current_val == "N")
      return nullptr;

    TreeNode *node = new TreeNode(stoi(current_val));
    node->left = dfs_deserialize(input);
    node->right = dfs_deserialize(input);

    return node;
  }
};
