#include <unordered_set>
#include <vector>
using std::vector;

/*
 * Goal: Check whether a sudoku is valid or not through 3 conditions
 * Row, Col, Box
 *
 * Intuition:
 * We can use hash set to store the number that is present in the current row, col and box.
 * We need to think up of a way to compute whether which box it locates at based on the i & j position
 * Time Complexity: O(n^2)
 * */
class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        std::vector<std::unordered_set<int>> row(9), col(9), box(9);

        for (int i{}; i < 9; i++)
            for (int j{}; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;

                int val{board[i][j] - '0'};

                // Check Row
                if (row[i].count(val))
                    return false;

                // Check Col
                if (col[j].count(val))
                    return false;

                // Check Box
                int box_pos{i / 3 * 3 + j / 3};
                if (box[box_pos].count(val))
                    return false;

                // all pass then insert into the set
                row[i].insert(val);
                col[j].insert(val);
                box[box_pos].insert(val);
            }
        return true;
    }
};
