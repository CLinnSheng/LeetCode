#include <algorithm>
#include <functional>
#include <vector>
/*
 *  Diagonals in bottom-left triangle are sorted in non-increasing order.
 *  Diagonals in top right triangle are sorted in non-decreasing order
 *
 *  Intuition:
 *  Ok so from the example given the bottom left will be distributed more.
 *  The main concern is just on how we traverse the grid because for the sorting part we can just simply push everything
 * into a heap.
 * Time Complexity: O(n^2 lg n )
 * */
class Solution
{
  public:
    std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>> &grid)
    {
        int ROWS(grid.size()), COLS(grid[0].size());

        for (int i{}; i < ROWS; i++)
        {
            std::vector<int> temp;
            for (int j{}; j + i < COLS; j++)
                temp.emplace_back(grid[i + j][j]);

            // Bottom Left
            // Descending Order
            std::sort(temp.begin(), temp.end(), std::greater<>());
            for (int j{}; j + i < COLS; j++)
                grid[i + j][j] = temp[j];
        }

        for (int j{1}; j < COLS; j++)
        {
            std::vector<int> temp;
            for (int i{}; i + j < COLS; i++)
                temp.emplace_back(grid[i][j + i]);

            // Bottom Left
            // Descending Order
            std::sort(temp.begin(), temp.end(), std::less<>());
            for (int i{}; i + j < COLS; i++)
                grid[i][j + i] = temp[i];
        }
        return grid;
    }
};
