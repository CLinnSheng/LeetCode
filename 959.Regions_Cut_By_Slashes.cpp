#include <bits/stdc++.h>
using namespace std;

/*
expand the grid where each cell is transform into a 3x3 cell
then populate the expanded cell with the slash
and then use bfs/dfs to fill out the empty spaces and + 1 
*/
class Solution {
public:
    const vector<pair<int, int>> direction{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int regionsBySlashes(vector<string>& grid) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int grid_size = grid.size();

        vector<vector<int>> expand_grid(grid_size * 3, vector<int>(grid_size * 3, 0));

        for (int i = 0; i < grid_size; i++)
            for (int j = 0; j < grid_size; j++) {
                // for expand grid
                int baseRow = i * 3, baseCol = j * 3;

                // Populate the expand_grid base on the shape
                if (grid[i][j] == '\\') {
                    expand_grid[baseRow][baseCol] = 1;
                    expand_grid[baseRow + 1][baseCol + 1] = 1;
                    expand_grid[baseRow + 2][baseCol + 2] = 1;
                }
                else if (grid[i][j] == '/') {
                    expand_grid[baseRow][baseCol + 2] = 1;
                    expand_grid[baseRow + 1][baseCol + 1] = 1;
                    expand_grid[baseRow + 2][baseCol] = 1;
                }
            }

            int region = 0;

            // Count the region by using bfs
            for (int i = 0; i < grid_size * 3; i++)
                for (int j = 0; j < grid_size * 3; j++) {
                    if (!expand_grid[i][j]){
                        bfs (expand_grid, i, j);
                        region++;
                    }
                }
        return region;
    }

    void bfs(vector<vector<int>> &expand_grid, int r, int c) {
        deque<pair<int, int>> queue;
        // mark the grid as visited
        expand_grid[r][c] = 1;
        queue.emplace_back(make_pair(r, c));

        while (!queue.empty()) {
            auto [x, y] = queue.front();
            queue.pop_front();

            for (const auto &[move_x, move_y] : direction) {
                int newR = x + move_x;
                int newC = y + move_y;

                if (newR >= 0 && newC >= 0 && newR < expand_grid.size() && newC < expand_grid.size() && !expand_grid[newR][newC]) {
                    expand_grid[newR][newC] = 1;
                    queue.emplace_back(make_pair(newR, newC));
                }
            }
        }
    }
};