#include <vector>

/*
 * Goal Find the minimum path sum from top left to bottom right
 * just return the path sum
 *
 * Intuition:
 * Ok this must be a graph problem --> DFS/BFS
 * DFS will be much more easier to implement
 * We can just recursively go through the grid and find the minimum path sum fro every possible path.
 * But we can see overlapping paths from if we go from (0,0)
 * */
class Solution
{
  public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
    }
};
