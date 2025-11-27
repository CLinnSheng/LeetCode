#include <utility>
#include <vector>
/*
 * Goal: Find the length of the longest increasing path in a matrix
 *
 * Intuition:
 * We just need to dfs from every single cell in the matrix
 * Time Complexity: O(m * n * 4^(m * n))
 *
 * Can optimize it through memoziation or caching because if you observe there is repetitive computation
 * Time Complexity: O(m * n)
 * */
class Solution
{
  private:
    std::vector<std::pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(const std::vector<std::vector<int>> &matrix, std::vector<std::vector<bool>> &visited,
            std::vector<std::vector<int>> &cache, int i, int j)
    {
        if (cache[i][j] != -1)
        {
            return cache[i][j];
        }

        visited[i][j] = true;

        int longest{};
        for (const auto &[di, dj] : directions)
        {
            int next_i = i + di;
            int next_j = j + dj;
            if (next_i >= 0 && next_i < matrix.size() && next_j >= 0 && next_j < matrix[0].size() &&
                matrix[next_i][next_j] > matrix[i][j] && !visited[next_i][next_j])
            {
                longest = std::max(longest, dfs(matrix, visited, cache, next_i, next_j));
            }
        }

        visited[i][j] = false;

        return cache[i][j] = 1 + longest;
    }

  public:
    int longestIncreasingPath(std::vector<std::vector<int>> &matrix)
    {
        int ans{};
        std::vector<std::vector<int>> cache(matrix.size(), std::vector<int>(matrix[0].size(), -1));

        for (int i{}; i < matrix.size(); i++)
            for (int j{}; j < matrix[i].size(); j++)
            {
                std::vector<std::vector<bool>> visited(matrix.size(), std::vector<bool>(matrix[i].size(), false));
                ans = std::max(ans, dfs(matrix, visited, cache, i, j));
            }

        return ans;
    }
};
