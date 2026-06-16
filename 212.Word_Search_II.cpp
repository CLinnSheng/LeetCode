#include <algorithm>
#include <array>
#include <functional>
#include <memory>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

/*
 * Goal: Return all words that are present in the grid
 *
 * Intuition:
 * All word can only be used once
 * We can use dfs to search the grid and backtracking when the string form doesnt match any of the prefix of the words.
 * The time complexity will be: O(N^2 * m^2) the m^2 is iterating through the words and check whether got this prefix or
 * not We can optimize this part by using a Trie Tree data structure to solve checking prefix
 * Trie Tree can optimize the checking of string by passing the currNode and check its flag
 * */

struct TrieNode
{
    std::array<std::shared_ptr<TrieNode>, 26> children;
    bool isWord{};

    TrieNode() : isWord(false)
    {
        std::fill(children.begin(), children.end(), nullptr);
    }
};

struct TrieTree
{
    std::shared_ptr<TrieNode> root;

    TrieTree()
    {
        root = std::make_shared<TrieNode>();
    }

    void insert(const std::string &str)
    {
        auto currNode = root;

        for (const auto ch : str)
        {
            if (currNode->children[ch - 'a'] == nullptr)
            {
                currNode->children[ch - 'a'] = std::make_shared<TrieNode>();
            }
            currNode = currNode->children[ch - 'a'];
        }

        currNode->isWord = true;
    }
};
class Solution
{
  private:
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words)
    {
        std::shared_ptr<TrieTree> tree = std::make_shared<TrieTree>();
        std::unordered_set<std::string> ans;
        int ROWS = board.size(), COLS = board[0].size();
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

        for (const auto &str : words)
        {
            tree->insert(str);
        }

        std::function<void(const int, const int, std::shared_ptr<TrieNode>, const std::string &)> backtracking =
            [&](const int row, const int col, std::shared_ptr<TrieNode> node, std::string currStr) {
                if (row < 0 || col < 0 || row >= ROWS || col >= COLS || visited[row][col] ||
                    node->children[board[row][col] - 'a'] == nullptr)
                {
                    return;
                }

                // Include this cell after boundary checking
                currStr += board[row][col];
                visited[row][col] = true;
                node = node->children[board[row][col] - 'a'];

                if (node->isWord)
                {
                    ans.insert(currStr);
                }

                for (const auto &[y, x] : DIRECTIONS)
                {
                    backtracking(row + y, col + x, node, currStr);
                }

                // Backtrack
                visited[row][col] = false;
            };

        // Try start from evey single cell
        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                backtracking(row, col, tree->root, "");
            }
        }
        return std::vector<std::string>(ans.begin(), ans.end());
    }
};
