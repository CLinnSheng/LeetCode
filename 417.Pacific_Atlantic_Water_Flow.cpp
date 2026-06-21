#include <functional>
#include <utility>
#include <vector>

/*
 * Find all the cells that can flow to both pacific and atlantic
 * Water can only flow into cell with height equal or lower
 * One important observation here is the cell at the edge sure can let water flow in
 * So each much more easier to start from the border
 * use dfs, since this is a graph problem with dfs we need to prevent visiting the same cell again
 * And how do we determine does the cell to both pacific and atlantic?
 * Is just simply reverse the quest, does water from both pacific and atlantic can flow to this cell?
 * Time Complexity: O(n*m)
 * */
class Solution
{
  private:
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights)
    {
        int ROWS = heights.size(), COLS = heights[0].size();
        std::vector<std::vector<bool>> pacific(ROWS, std::vector<bool>(COLS, false)),
            atlantic(ROWS, std::vector<bool>(COLS, false));

        std::function<void(const int, const int, std::vector<std::vector<bool>> &)> dfs =
            [&](const int row, const int col, std::vector<std::vector<bool>> &visited) {
                // Mark visited
                visited[row][col] = true;

                for (const auto &[_row, _col] : DIRECTIONS)
                {
                    int new_row = _row + row;
                    int new_col = _col + col;

                    if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS || visited[new_row][new_col] ||
                        heights[row][col] > heights[new_row][new_col])
                    {
                        continue;
                    }

                    dfs(new_row, new_col, visited);
                }
            };

        for (int row{}; row < ROWS; row++)
        {
            dfs(row, 0, pacific);
            dfs(row, COLS - 1, atlantic);
        }

        for (int col{}; col < COLS; col++)
        {
            dfs(0, col, pacific);
            dfs(ROWS - 1, col, atlantic);
        }

        std::vector<std::vector<int>> ans;

        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                if (atlantic[row][col] && pacific[row][col])
                {
                    ans.push_back({row, col});
                }
            }
        }
        return ans;
    }
};
