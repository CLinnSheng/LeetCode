#include <utility>
#include <vector>

/*
 * Given a m * n grid where grid[i][j] could be:
 * 1 representing the starting square
 * 2 represting the ending square
 * 0 representing empty square
 * -1 representing the obstacle
 *
 *  Goal: Return the number of paths from the starting sqaure to the ending square.
 *  Constraint: Every walkable cell must be visit
 *
 *  Intuition:
 *  This is a graph problem can either use dfs/bfs.
 *  We choose dfs over here is easy and just backtrack
 *  IMPORTANT THINGS IS we needed visit every single empty cell
 *  so what we can do is we keep track of the number of step we have travel
 * Time Complexity: O(m*n)
 * Space Complexity: O(m*n)
 * */
class Solution
{
  public:
    std::pair<int, int> startingPosition, endingPosition;
    std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int emptyCell{};

    void findPosition(const std::vector<std::vector<int>> &grid)
    {
        for (int i{}; i < grid.size(); i++)
            for (int j{}; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    startingPosition = std::make_pair(i, j);
                else if (grid[i][j] == 2)
                    endingPosition = std::make_pair(i, j);
                else if (grid[i][j] == 0)
                    emptyCell++;
    }

    int dfs_backtracking(const int &currRow, const int &currCol, const int &currentStep,
                         std::vector<std::vector<int>> &grid)
    {
        // Base-Cases
        // check whether reach the end cell
        if (currRow == endingPosition.first && currCol == endingPosition.second)
            return currentStep - 1 == emptyCell;

        // check whether it is out of bound
        if (currRow < 0 || currCol < 0 || currRow >= grid.size() || currCol >= grid[0].size() ||
            grid[currRow][currCol] == -1)
            return 0;

        // mark the cell as visited
        int temp{grid[currRow][currCol]};
        grid[currRow][currCol] = -1;

        // traverse the graph
        int ttlPath{};
        for (const auto &direction : DIRECTIONS)
            ttlPath += dfs_backtracking(currRow + direction.first, currCol + direction.second, currentStep + 1, grid);

        // backtrack
        grid[currRow][currCol] = temp;

        return ttlPath;
    }
    int uniquePathsIII(std::vector<std::vector<int>> &grid)
    {
        // first find out the starting position and ending position first
        findPosition(grid);
        // dfs
        // the parameter we needed is the row, col, number_of_step
        return dfs_backtracking(startingPosition.first, startingPosition.second, 0, grid);
    }
};
