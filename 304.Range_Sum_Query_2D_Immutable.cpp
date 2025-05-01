#include <vector>

/*
 * Goal: Return the sum of the elements of matrix inside the rectangle defined by the upper left corner and lower right
 * corner.
 *
 * Intuition:
 * The brute force way will just simply iterate throuh every single elment within the rectangle
 * But this will take O(n^2)
 *
 * How can we optimize it to O(1) for SumRegion??
 * The way only we is to use prefixSum. For the normal prefixSum is llike prefixSum[i] means the sum from 0 to ith.
 * But how do we design it such that it can use for 2d matrix?
 * The O(n) way will is take the prefix sum of the col2 - sum of the the col1 and iterate through the array between row1
 * and row2. How do we make it O(1)?
 *
 * We can design our prefix sum such that prefixSum[i][j] will be the sum of all the elements before ith and jth.
 * eg: prefixSum[1][1] will be the sum of all element nums[0][0], nums[0][1], nums[1][0], nums[1][1]
 * and then how do we compute the sum of the particular rectangle
 * the fomrula is prefixsum of bottom right - prefixsum bottom left -1 - prefixsum top right - 1 + prefixsum top left -
 * 1
 * */
class NumMatrix
{
  private:
    std::vector<std::vector<int>> prefixSum;

  public:
    NumMatrix(std::vector<std::vector<int>> &matrix)
    {
        int ROW(matrix.size()), COL(matrix[0].size());
        // need to offset 1 because of row 0 and col 0
        prefixSum = std::vector<std::vector<int>>(ROW + 1, std::vector<int>(COL + 1, 0));

        for (int i{}; i < ROW; i++)
        {
            int sum{};

            for (int j{}; j < COL; j++)
            {
                sum += matrix[i][j];

                // remeber the prefixSum is offset by 1
                int above{prefixSum[i][j + 1]};
                prefixSum[i + 1][j + 1] = sum + above;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        // REMEMBER OFF SET BY1
        row1++;
        col1++;
        row2++;
        col2++;

        int bottomRight{prefixSum[row2][col2]};
        int bottomLeft{prefixSum[row2][col1 - 1]};
        int topRight{prefixSum[row1 - 1][col2]};

        // add back the area got minus twice
        return bottomRight - bottomLeft - topRight + prefixSum[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
