#include <functional>
#include <string>
#include <unordered_map>
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
 * */

struct TrieNode
{
    std::unordered_map<int, TrieNode *> alphabets;
    bool isWord;

    TrieNode() : isWord(false)
    {
    }

    void addWord(const std::string &str)
    {
        auto temp{this};

        for (const auto &ch : str)
        {
            if (temp->alphabets.find(ch - 'a') == temp->alphabets.end())
                temp->alphabets[ch - 'a'] = new TrieNode();

            temp = temp->alphabets[ch - 'a'];
        }

        temp->isWord = true;
    }
};
class Solution
{
  private:
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words)
    {
        std::unordered_set<std::string> answer;
        if (words.size() == 0)
            return {};

        int ROWS(board.size()), COLS(board[0].size());
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

        TrieNode *root = new TrieNode();
        for (const auto &word : words)
            root->addWord(word);

        std::function<void(const int &, const int &, TrieNode *, std::string)> dfs_backtracking =
            [&](const int &row, const int &col, TrieNode *currNode, std::string word) {
                if (row < 0 || col < 0 || row >= ROWS || col >= COLS || visited[row][col] ||
                    currNode->alphabets[board[row][col] - 'a'] == nullptr)
                    return;

                visited[row][col] = true;
                word += board[row][col];
                currNode = currNode->alphabets[board[row][col] - 'a'];

                if (currNode->isWord)
                    answer.insert(word);

                for (const auto &direction : DIRECTIONS)
                {
                    int newRow{direction.first + row}, newCol{direction.second + col};

                    dfs_backtracking(newRow, newCol, currNode, word);
                }

                visited[row][col] = false;
            };

        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
                dfs_backtracking(i, j, root, "");
        return std::vector<std::string>(answer.begin(), answer.end());
    }
};
