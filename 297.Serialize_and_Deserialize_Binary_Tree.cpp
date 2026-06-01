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
 * So we need to serialize into strings
 * So we need to have a delimiter to differentiate each node and also handling nullptr
 * We can choose either any kind of traversal.
 * We will be using preorder traversal over here
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
#include <functional>
#include <string>
#include <vector>
class Codec
{
  private:
    std::string join(const std::vector<std::string> &tokens, const std::string &delimiter)
    {
        std::string ans{};

        for (const auto &token : tokens)
        {
            // Compare the address because some nodes might have the same value
            if (&token != &tokens[0])
            {
                ans += delimiter;
            }

            ans += token;
        }
        return ans;
    }

    std::vector<std::string> split(const std::string &data, const char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(data);

        while (std::getline(tokenStream, token, delimiter))
            tokens.emplace_back(token);

        return tokens;
    }

  public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root)
    {
        std::vector<std::string> tokens;

        std::function<void(TreeNode *)> dfs_serialize = [&](TreeNode *node) {
            if (node == nullptr)
            {
                tokens.emplace_back("N");
                return;
            }

            tokens.emplace_back(std::to_string(node->val));

            dfs_serialize(node->left);
            dfs_serialize(node->right);
        };

        dfs_serialize(root);

        return join(tokens, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        // Reverse the process of deseriliaze
        // Store into a vector of token by removing the delimiter
        std::vector<std::string> tokens = split(data, ',');
        int index{};

        // Build the tree from preorder traversal
        std::function<TreeNode *(int &)> dfs_deserialize = [&](int &index) -> TreeNode * {
            if (tokens[index] == "N")
            {
                index++;
                return nullptr;
            }

            TreeNode *node = new TreeNode(std::stoi(tokens[index++]));
            node->left = dfs_deserialize(index);
            node->right = dfs_deserialize(index);

            return node;
        };

        return dfs_deserialize(index);
    }
};
