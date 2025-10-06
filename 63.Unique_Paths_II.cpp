#include <vector>
/*
 * the robot tries to move to bottom right. and the robot can only move either down or right at any point in time
 * we can only take path there dont get into any square have obstacle
 * goal: return the number of possible unique paths that the robot can reach the bottom right corner
 *
 *
 * intuition:
 * is about the same as unique_path i. ok so we basically at every cell we can either moves 2 way either down or right.
 * so we can just recursively get the number of paths from moving down and right. now we just need another layer of
 * checking whether the cell is legit or not.
 * time complexity: o(n^n)
 *
 *  we can improve it by using caching
 *  time complexity: o(n^2)
 * */
class Solution
{

  private:
    int dfs_caching(std::vector<std::vector<int>> &obstaclegrid, const int rows, const int cols, const int row,
                    const int col, std::vector<std::vector<int>> &caching)
    {
        // check whether is it a legit grid or not first
        if (row < 0 || row >= rows || col < 0 || col >= cols || obstaclegrid[row][col])
            return 0;

        if (row == rows - 1 && col == cols - 1)
            return 1;

        if (caching[row][col] != -1)
            return caching[row][col];

        return caching[row][col] = dfs_caching(obstaclegrid, rows, cols, row + 1, col, caching) +
                                   dfs_caching(obstaclegrid, rows, cols, row, col + 1, caching);
    }

  public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstaclegrid)
    {
        int rows(obstaclegrid.size()), cols(obstaclegrid[0].size());
        std::vector<std::vector<int>> caching(rows, std::vector<int>(cols, -1));
        return dfs_caching(obstaclegrid, rows, cols, 0, 0, caching);
    }
};
