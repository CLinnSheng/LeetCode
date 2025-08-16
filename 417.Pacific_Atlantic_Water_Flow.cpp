#include <functional>
#include <utility>
#include <vector>

/*
 * Goal: Find all cells where water can flow from both ocean
 *
 * Intuition:
 * This is a graph problem. So is either using bfs or dfs.
 * Both traversing algorithm works but dfs will be much more easier.
 * So our goal is to find all those cell where water can flow into it. Water can only flow from high val cell to low val
 * cell
 * One key important observatoin is all the cells at the border sure can let water flow in.
 * So we can traverse from the border. Then we can have an array for each ocean to mark those cell that visited.
 * So we simply need to find those intersect cells
 *
 * Time Complexity: O(m * n)
 *
 * */
class Solution
{
  private:
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights)
    {
        int ROWS(heights.size()), COLS(heights[0].size());
        std::vector<std::vector<int>> answer;

        // Visited Cell
        std::vector<std::vector<bool>> pacific(ROWS, std::vector<bool>(COLS, false)),
            atlantic(ROWS, std::vector<bool>(COLS, false));

        std::function<void(const int &, const int &, std::vector<std::vector<bool>> &)> dfs =
            [&](const int &row, const int &col, std::vector<std::vector<bool>> &visited) {
                visited[row][col] = true;

                for (const auto &direction : DIRECTIONS)
                {
                    int newRow{direction.first + row}, newCol{direction.second + col};

                    if (newRow < 0 || newCol < 0 || newRow >= ROWS || newCol >= COLS || visited[newRow][newCol] ||
                        heights[newRow][newCol] < heights[row][col])
                        continue;

                    dfs(newRow, newCol, visited);
                }
            };

        for (int i{}; i < COLS; i++)
        {
            dfs(0, i, pacific);
            dfs(ROWS - 1, i, atlantic);
        }
        for (int i{}; i < ROWS; i++)
        {

            dfs(i, 0, pacific);
            dfs(i, COLS - 1, atlantic);
        }

        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
                if (atlantic[i][j] && pacific[i][j])
                    answer.emplace_back(std::vector<int>{i, j});
        return answer;
    }
};
