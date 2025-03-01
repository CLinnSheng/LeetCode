#include <functional>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

/*
Goal: Return the number of islands in grid2 that are considered sub-islands
An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up
this island in grid2 Intuition: First we flood fill the grid2 with respect to grid1 for checking whether that subisland
is a legit subisland or not by using dfs & recursive approach to serach through grid2 Time Complexity: O(n2)
*/
class Solution
{

  public:
    const std::vector<std::pair<int, int>> direction{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int countSubIslands(std::vector<std::vector<int>> &grid1, std::vector<std::vector<int>> &grid2)
    {

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int n_rows = grid1.size(), n_cols = grid1[0].size();
        int n_subIsland = 0;

        // Keep track of the visited cells
        std::vector<std::vector<bool>> visited(n_rows, std::vector<bool>(n_cols, false));

        std::function<bool(int, int)> checkSubIsland = [&](int r, int c) {
            bool isSubIsland = true;

            // Check whether the current cell in grid2 is exist in grid1 or not
            if (grid1[r][c] == 0)
                // we dont straight away return because we want to make this whole pieces of island in grid2 to be
                // invalid subisland
                isSubIsland = false;

            // dfs from this cell
            for (const auto &[x, y] : direction)
            {
                int new_r = r + x;
                int new_c = c + y;

                // dfs and check the boundary, visited before or not and whether is it an island
                if (new_r >= 0 && new_c >= 0 && new_r < n_rows && new_c < n_cols && !visited[new_r][new_c] &&
                    grid2[new_r][new_c])
                {
                    visited[new_r][new_c] = true;

                    // dfs & recursively call until to check whether all the cell in this subisland is subset of the
                    // subisland in grid1 or not
                    bool nextSubIsland = checkSubIsland(new_r, new_c);
                    isSubIsland = isSubIsland && nextSubIsland;

                    // Take note from here we dont do isSubIsland = isSubIsland && checkSubIsland(new_r, new_c)
                    // because if the current cell already invalid then the other half will not be call causing only
                    // this particular cell in grid2 is not considered we want to make this whole subIsland to be
                    // invalid
                }
            }

            return isSubIsland;
        };

        for (int i = 0; i < n_rows; i++)
            for (int j = 0; j < n_cols; j++)
                // dfs through grid2
                if (grid2[i][j] && !visited[i][j])
                {
                    // mark this cell visited
                    visited[i][j] = true;

                    // check whether is this a legit subisland
                    if (checkSubIsland(i, j))
                        n_subIsland++;
                }
        return n_subIsland;
    }
};
