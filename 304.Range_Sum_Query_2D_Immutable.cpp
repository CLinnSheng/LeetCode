#include <vector>
using std::vector;

/*
 * Goal: Implement the NumMatrix Class
 * The constructor initializes the object with the integer matrix.
 * sumRegion function return the sum of elements of matrix inside the rectangle defined by its
 * upper left corner and lower right corner.
 *
 *
 * */
class NumMatrix
{
  public:
    std::vector<std::vector<int>> prefixSum;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int ROWS(matrix.size()), COLS(matrix[0].size());
        prefixSum = std::vector<std::vector<int>>(ROWS + 1, std::vector<int>(COLS + 1, 0));

        for (int row{}; row < ROWS; row++)
        {
            int sum{};
            for (int col{}; col < COLS; col++)
            {
                sum += matrix[row][col];
                int above{prefixSum[row][col + 1]};
                prefixSum[row + 1][col + 1] = sum + above;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        // just iterate every single row & col within the rectangle
        // this is the brute force way. Time Complexity: O(m*n)
        // How can we make it in O(1)? the only way is to precopmute the sum (prefix) at every index
        // but just finding the prefix of a row still couldnt achieve O(1) [actual time complexity: O(m)]
        // the way to compute the prefix is we find the row 1 & also add the above this will make the prefix of the
        // rectangle
        // int sum{};
        //
        // for (int i{row1}; i <= row2; i++)
        //     for (int j{col1}; j <= col2; j++)
        //         sum += matrix[i][j];
        //
        // return sum;

        // fix the offset first
        row1++;
        col1++;
        row2++;
        col2++;
        int bottomRight = prefixSum[row2][col2];
        int topRight = prefixSum[row1 - 1][col2];
        int bottomLeft = prefixSum[row2][col1 - 1];

        // we add because we minus the area twice
        return bottomRight - topRight - bottomLeft + prefixSum[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
