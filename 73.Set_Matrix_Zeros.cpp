#include <vector>

/*
 * Given an element m*n, if an element is 0 set its entire row and column to 0's
 * Constraint: Must do it inplace
 *
 * Intuition:
 * Take note we can only transform the entire row and column to 0 based on the original element of the matrix
 * How do we keep track of the original 0's? without using any extra space or O(1)
 * We can set the flag at the beginning of the row and col.
 * But how do we handle if the first col of the row is zero? because we always refer to the first col of the row of the
 * first row of the col which is itself So we will have another flag for setting if the '0' is in the first col of the
 * row.
 *
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
 * */
class Solution
{
  public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        int m(matrix.size()), n(matrix[0].size());
        bool zeroInFirstCol{false};
        for (int i{}; i < m; i++)
        {
            // to handle cases where the first col is '0'
            // so that the col above and under it will be set to 0 as well because through checking the row first col
            // and the col of first row it wont set it to 0
            if (matrix[i][0] == 0)
                zeroInFirstCol = true;

            // we dun set for first col because it cause error as it will update the first row of the first col to be 0
            // and causing the flag become wrong as the first row will thought the whole row be zero
            // so we just make use of the zeroInfirstCol flag to check whether the first col is set to 0 or not
            for (int j{1}; j < n; j++)
                // setting the flag to indicate the entire row & col will be set 0
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }

        // take note we must traverse in the opposite direction because
        // if we dont we are checking the value that are being changed
        for (int i{m - 1}; i >= 0; i--)
        {
            // the first col should be check through the zeroInFirstCol flag
            // same reason as above
            for (int j{n - 1}; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

            if (zeroInFirstCol)
                matrix[i][0] = 0;
        }
    }
};
