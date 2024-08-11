#include <bits/stdc++.h>
using namespace std;

/*
Intuition: Stimulate the process
magic grid is 3x3 square, so we try to find all possible 3x3 square and check whether it is a magic square
*/
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int ans = 0;
        int n_row = grid.size(), n_col = grid[0].size();

        function<int(int, int)> magic = [grid](int r, int c) {

            unordered_set<int> set;

            // check whether can form a matrix or not
            for (int i = r; i < r + 3; i++)
                for (int j = c; j < c + 3; j++) {
                    int temp = grid[i][j];
                    if (set.count(temp) || temp < 1 || temp > 9)
                        return 0;
                    set.emplace(temp);
                }

            // checking whether is it a magic square (row, col & diag equals to 15)
            // rows
            for (int i = r; i < r + 3; i++)  
                if (grid[i][c] + grid[i][c + 1] + grid[i][c + 2] != 15)
                    return 0;

            // cols
            for (int i = c; i < c + 3; i++)
                if (grid[r][i] + grid[r + 1][i] + grid[r + 2][i] != 15)
                    return 0;

            /// diagonals
            if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15 || grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15)
                return 0;

            return 1;
        };

        // since magic grid is 3x3, so we check until r - 2
        for (int i = 0; i < n_row - 2; i++)
            for (int j = 0; j < n_col - 2; j++)
                // call a function to compute a magic grid
                ans += magic(i, j);

        return ans;
    }


};