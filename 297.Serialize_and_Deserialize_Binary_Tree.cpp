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
 * Serialize: Process of converting an in-memory structure into a sequence of bits
 * Task: Ensure binary tree can be serialize into a string and can be deserialized to the original tree structure.
 *
 * Intuition:
 * The treeNode is in level order traversal. How do we serialize into a string while still can handle nullptr
 *
 * */
#include <functional>
#include <sstream>
#include <string>
#include <vector>
class Codec
{
  private:
    std::string join(const std::vector<std::string> &str, const std::string &delimiter)
    {
        std::string answer{};

        for (const auto &s : str)
        {
            if (&s != &str[0])
                answer += delimiter;

            answer += s;
        }
        return answer;
    }

    void split(std::vector<std::string> &answer, const std::string &data, const char &delimiter)
    {
        std::string token;
        std::istringstream tokenStream(data);

        while (std::getline(tokenStream, token, delimiter))
            answer.push_back(token);
    }

  public:
    // Encodes a tree to a single string.
    // a leaf can just represent with 2 nullptr follow by it
    // Preorder Traversal
    string serialize(TreeNode *root)
    {
        std::vector<std::string> answer;
        std::function<void(TreeNode *)> serializeHelperDFS = [&](TreeNode *node) {
            if (node == nullptr)
            {
                answer.emplace_back("N");
                return;
            }

            answer.emplace_back(std::to_string(node->val));
            serializeHelperDFS(node->left);
            serializeHelperDFS(node->right);
        };

        serializeHelperDFS(root);
        return join(answer, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        std::vector<std::string> answer;
        split(answer, data, ',');
        int index{};

        std::function<TreeNode *(int &)> deserializeHelperDFS = [&](int &index) -> TreeNode * {
            // Base Case
            if (answer[index] == "N")
            {
                index++;
                return nullptr;
            }

            TreeNode *node = new TreeNode(std::stoi(answer[index++]));
            node->left = deserializeHelperDFS(index);
            node->right = deserializeHelperDFS(index);

            return node;
        };

        return deserializeHelperDFS(index);
    }
};
