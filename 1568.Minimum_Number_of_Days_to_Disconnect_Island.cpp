#include <bits/stdc++.h>
using namespace std;

/*
There are 3 possible days to disconnect island which is 0, 1 and 2
Maximum is only 2 where we only need to remove the most edges piece

*/
class Solution {
    const vector<pair<int, int>> direction{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minDays(vector<vector<int>>& grid) {

        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n_row = grid.size(), n_col = grid[0].size();

// Initially is either only 1 whole big piece of island or not island at all
        if (countIsland(grid) != 1)
            return 0; 

        // Try to remove the island
        // Since we already know that the possible answer is 0, 1 and 2
        // Since from the line above, we can tell that theres a only piece of land
        // so we only the ans left with 1 or 2
        for (int i = 0; i < n_row; i++)
            for (int j = 0; j < n_col; j++) {
                if (!grid[i][j])
                    continue;

                // Temporary remove this piece of land
                grid[i][j] = 0;

                // then see whether did we successfully disconnect the island
                if (countIsland(grid) != 1)
                    return 1;
                
                // if didnt remove we recover it
                grid[i][j] = 1;
            }   

    // 2 is the only choice
        return 2;
    }

    int countIsland(vector<vector<int>> &grid) {

        int n_row = grid.size(), n_col = grid[0].size();
        int island_cnt = 0;

        vector<vector<bool>> visited(n_row, vector<bool>(n_col, false));
        
        // explore all the land
        for (int i = 0; i < n_row; i++)
            for (int j = 0; j < n_col; j++)
                if (!visited[i][j] && grid[i][j]) {
                    exploreIsland(grid, i, j, visited);
                    island_cnt++;
                }

        return island_cnt;
    }

    // dfs to explore all the land
    void exploreIsland(vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &visited) {

        // mark this piece of land is visited
        visited[r][c] = true;

        // dfs all the possible directions
        for (const auto &[x, y] : direction) {
            int new_x = x + r;
            int new_y = y + c;

            if (new_x >= 0 && new_y >= 0 && new_x < grid.size() && new_y < grid[0].size() && !visited[new_x][new_y] && grid[new_x][new_y])
                exploreIsland(grid, new_x, new_y, visited);
        }

    }
};