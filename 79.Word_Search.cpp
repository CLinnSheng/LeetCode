// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::pair<int, int>> direction{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int len = word.length();
    if (len == 0)
      return true;

    std::vector<std::vector<bool>> visited(
        board.size(), std::vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); i++)
      for (int j = 0; j < board[0].size(); j++) {
        if (helper(i, j, word, board, visited, 0))
          return true;
        visited[i][j] = false;
      }

    return false;
  }

  bool helper(int r, int c, const std::string &word,
              const std::vector<std::vector<char>> &board,
              std::vector<std::vector<bool>> &visited, int index) {

    visited[r][c] = true;
    if (index < word.length() && board[r][c] != word[index])
      return false;
    if (index == word.length() - 1)
      return true;

    for (const auto &[_r, _c] : direction) {
      auto new_r = _r + r;
      auto new_c = _c + c;

      if (new_r >= 0 && new_c >= 0 && new_r < board.size() &&
          new_c < board[0].size() && !visited[new_r][new_c]) {
        if (helper(new_r, new_c, word, board, visited, index + 1))
          return true;
        // backtrack
        visited[new_r][new_c] = false;
      }
    }
    return false;
  }
};
