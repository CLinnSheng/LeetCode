#include <array>
#include <iostream>
#include <string>
#include <vector>

/*
Goal: Find all the words on the board that is from the array of strings, word
Constraint: Each string from the words can only be used once
Intuition: We can use dfs and backtracking from every single point on the board.
But this is very costly because if the first few characters are not the same we
still try to search through all the coordinates. Optimization: We will stop once
the characters do not follow the string from the words. We can use Trie trees.
*/

const std::vector<std::pair<int, int>> DIRECTIONS = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class TrieTree {
public:
  std::array<TrieTree *, 26> alphabets; // Use raw pointers
  bool isWord;
  int nWords; // Track how many words are available at every node in the tree

  TrieTree() : isWord{false}, nWords{0} {
    std::fill(alphabets.begin(), alphabets.end(), nullptr);
  }

  // Insert word into Trie
  void insert_word(const std::string &str) {
    TrieTree *temp = this; // Use raw pointer instead of shared_ptr
    temp->nWords++;
    for (const auto &c : str) {
      auto char_to_num = c - 'a';

      if (temp->alphabets[char_to_num] == nullptr)
        temp->alphabets[char_to_num] =
            new TrieTree(); // Allocate new TrieTree node
      temp = temp->alphabets[char_to_num];
      temp->nWords++;
    }
    temp->isWord = true;
  }

  // Remove word from Trie
  void remove_word(const std::string &str) {
    TrieTree *temp = this; // Use raw pointer
    temp->nWords--;
    for (const auto &c : str)
      if (temp->alphabets[c - 'a']) {
        temp = temp->alphabets[c - 'a'];
        temp->nWords--;
      }
  }

  // Destructor to free allocated memory
  ~TrieTree() {
    for (auto &node : alphabets)
      if (node != nullptr)
        delete node;
  }
};

class Solution {
public:
  std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                     std::vector<std::string> &words) {

    std::vector<std::vector<bool>> visited(
        board.size(), std::vector<bool>(board[0].size(), false));
    std::vector<std::string> ans;
    TrieTree *root = new TrieTree(); // Use raw pointer for TrieTree

    // Add the words into the trie tree
    for (const auto &word : words)
      root->insert_word(word);

    // DFS and backtracking function
    std::function<void(int, int, std::string, TrieTree *, TrieTree *)>
        dfs_backtracking = [&](int row, int col, std::string curr_string,
                               TrieTree *curr_node) {
          if (row < 0 || col < 0 || row >= board.size() ||
              col >= board[0].size() || visited[row][col] ||
              curr_node->alphabets[board[row][col] - 'a'] == nullptr ||
              curr_node->alphabets[board[row][col] - 'a']->nWords <= 0)
            return;

          visited[row][col] = true;
          curr_string += board[row][col];
          curr_node = curr_node->alphabets[board[row][col] - 'a'];

          // Check if we found a word
          if (curr_node->isWord) {
            curr_node->isWord = false; // Mark word as found
            ans.emplace_back(curr_string);
            root->remove_word(curr_string);
          }

          // Perform DFS in all directions
          for (const auto &[dx, dy] : DIRECTIONS) {
            int new_row = row + dx;
            int new_col = col + dy;

            dfs_backtracking(new_row, new_col, curr_string, root, curr_node);
          }

          // backtrack
          visited[row][col] = false;
        };

    // Start DFS from every point on the board
    for (int i = 0; i < board.size(); i++)
      for (int j = 0; j < board[0].size(); j++)
        dfs_backtracking(i, j, "", root);

    delete root; // Don't forget to free the root to avoid memory leak
    return std::move(ans);
  }
};
