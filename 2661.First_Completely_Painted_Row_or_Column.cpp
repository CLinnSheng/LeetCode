#include <unordered_map>
#include <utility>
#include <vector>

/*
 * Given a 0-index integer array, arr and an m*n matrix, mat.
 * arr & mat contain all the integers in the range [1, m*n]
 * Go through each index i in arr starting from 0 & paint the cell in mat containing the integer arr[i]
 * Goal: Return the smallest index i at which either a row or column will be completely painted in mat
 *
 * Intuition:
 * So i dont really have to iterate finish the arr, just until a row or a column is completely painted.
 * But the problem is how do i know arr[i] is at which index at mat?
 * we can use a hash data structure to store the position of a value from the mat
 * and then check the row & col every time we paint a cell
 * Time Complexity: O(m*n(m))
 *
 * How can we optimize this?
 * Can we make the checking in O(1)?
 * We can actually use array data structure because u can observe during the dry run.
 * Each m row has n column anad each n column has m row.
 * So we can store the frequecny and whenever a row or a column reach 0 then that means
 * every row or column in that specific row or column is painted
 * Time Complexity: O(m*n)
 * Space Complexity: O(m*n)
 * */
class Solution
{
  private:
    bool checkResult(const int &row, const int &col, const int &ROWS, const int &COLS,
                     const std::vector<std::vector<bool>> &paintedCells)
    {
        bool paint{true};

        // check row
        for (int i{}; i < COLS; i++)
            if (paintedCells[row][i] == false)
            {
                paint = false;
                break;
            }

        if (paint)
            return paint;

        paint = true;

        for (int i{}; i < ROWS; i++)
            if (paintedCells[i][COLS] == false)
            {
                paint = false;
                break;
            }

        return paint;
    }

  public:
    int firstCompleteIndex(std::vector<int> &arr, std::vector<std::vector<int>> &mat)
    {
        int ROWS(mat.size()), COLS(mat[0].size());
        std::unordered_map<int, std::pair<int, int>> valPosition;

        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
                valPosition[mat[i][j]] = std::make_pair(i, j);

        // Brute Force:
        // O(m*n(m))
        // std::vector<std::vector<bool>> paintedCells(ROWS, std::vector<bool>(COLS, false));
        // for (int i{}; i < ROWS * COLS; i++)
        // {
        //     int row{valPosition[arr[i]].first}, col{valPosition[arr[i]].second};
        //     paintedCells[row][col] = true;
        //
        //     if (checkResult(row, col, ROWS, COLS, paintedCells))
        //         return i;
        // }

        std::vector<int> rowPaint(ROWS, COLS), colPaint(COLS, ROWS);
        for (int i{}; i < ROWS * COLS; i++)
        {
            int row{valPosition[arr[i]].first}, col{valPosition[arr[i]].second};
            if (--rowPaint[row] == 0 || --colPaint[col] == 0)
                return i;
        }
        return -1;
    }
};
