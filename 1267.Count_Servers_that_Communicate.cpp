#include <vector>
using std::vector;

/*
 * Given grid a 2d array where grid[i][j] = 1 means got server otherwise no server
 * Two servers are said to be communicate if they are on the same row or on the same column
 *
 * Intuition:
 * The servers not need to be adjacent in order to connect as long as they're on the same
 * row or column.
 * The simplest way is just to find out the number of computer availables in every single row & col
 * Then loop thorugh the 2d array. if it cell (row, col) got more than 1 in both row or col
 * then consider the computer is able to communicate
 * Time Complexity: O(m*n)
 * Space Complexity: O(m*n)
 * */
class Solution
{
  public:
    int countServers(vector<vector<int>> &grid)
    {
        int ROWS(grid.size()), COLS(grid[0].size());
        vector<int> computerRow(ROWS, 0), computerCol(COLS, 0);

        for (int row{}; row < ROWS; row++)
            for (int col{}; col < COLS; col++)
                if (grid[row][col])
                {
                    computerRow[row]++;
                    computerCol[col]++;
                }

        int ttl{};

        for (int row{}; row < ROWS; row++)
            for (int col{}; col < COLS; col++)
                if (grid[row][col])
                    // either row or col have more than computer
                    ttl += computerRow[row] || computerCol[col];

        return ttl;
    }
};
