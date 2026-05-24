/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

/*
 * Leaf Node -> All values in the grid has the same value
 * Internal Node -> Mix of 1s and 0s
 *
 * So we need to keep splitting the grid into 4 equal smaller grid
 * From the 'keep splitting' -> This lead us to use dfs/recursive
 * */
#include <vector>
class Solution
{
    Node *dfs(const std::vector<std::vector<int>> &grid, int size, int row, int col)
    {
        // First we need to check is it a leaf or not
        // By checking all the cell
        bool isLeaf{true};
        for (int i{}; i < size; i++)
        {
            for (int j{}; j < size; j++)
            {
                if (grid[row][col] != grid[row + i][col + j])
                {
                    isLeaf = false;
                    break;
                }
            }
        }

        // Base Case --> Leaf Node
        if (isLeaf)
        {
            return new Node(grid[row][col] == 1, true);
        }

        // Recursive dividing into 4 smaller grid
        Node *topLeft = dfs(grid, size / 2, row, col);
        Node *topRight = dfs(grid, size / 2, row, col + size / 2);
        Node *bottomleft = dfs(grid, size / 2, row + size / 2, col);
        Node *bottomRight = dfs(grid, size / 2, row + size / 2, col + size / 2);

        return new Node(grid[row][col] == 1, false, topLeft, topRight, bottomleft, bottomRight);
    }

  public:
    Node *construct(vector<vector<int>> &grid)
    {
        return dfs(grid, grid.size(), 0, 0);
    }
};
