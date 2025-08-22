#include <algorithm>
#include <climits>
#include <vector>
using std::vector;

/*
 * Goal: Find the minimum area of rectangle
 *
 * Intuition:
 * Since we only finding the area that will cover all the ones.
 * So we can simply just ignore the 0s, and need take position of all ones.
 * We are finding the rectangle so we need the coordinates of all the one.
 * Actually we only need the coordinates on the 4 point.
 * We can simply just keep track the min row, col and max row and col
 *
 * Time Complexity: O(M*N)
 * */
class Solution
{
  public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int minRow{INT_MAX}, minCol{INT_MAX}, maxRow{INT_MIN}, maxCol{INT_MIN};
        int ROWS(grid.size()), COLS(grid[0].size());

        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
                if (grid[i][j])
                {
                    minRow = std::min(minRow, i);
                    minCol = std::min(minCol, j);
                    maxRow = std::max(maxRow, i);
                    maxCol = std::max(maxCol, j);
                }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
