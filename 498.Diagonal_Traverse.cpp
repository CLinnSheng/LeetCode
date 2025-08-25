#include <vector>

/*
 * Goal: Return the elements in diagonal order
 *
 * Intuition:
 * The matrix was given m * n sizes.
 * So it is not always a square matrix
 * Notice that it start and end at 1. For the middle part it will keep increasing until a maximum point then decreases
 * back to 1
 * So every time out of bound we will either increase or decrease
 * And also the order of next element when out of bound is also keep switching.
 * When going diagonal down --> [i][j + 1]
 * when going diagonal up --> [i - 1][j]
 * In simpler terms: stimulation
 *
 * Time Complexity: O(m * n)
 * */
class Solution
{
  public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>> &mat)
    {
        std::vector<int> answer;
        bool direction{1}; // 1 -> Up, 0 -> Down

        int ROWS(mat.size()), COLS(mat[0].size());
        int row{}, col{};

        while (row < ROWS && col < COLS)
        {
            // Base Case to break out of the loop
            if (answer.size() == ROWS * COLS)
                break;

            answer.emplace_back(mat[row][col]);

            // Next cell
            int nextRow{direction ? row - 1 : row + 1};
            int nextCol{direction ? col + 1 : col - 1};

            // Determine Out of bound or not
            if (nextRow < 0 || nextCol < 0 || nextRow >= ROWS || nextCol >= COLS)
            {
                // Next Cell is also depends on current direction
                if (direction)
                {
                    nextRow = row + (col == COLS - 1 ? 1 : 0);
                    nextCol = col + (col == COLS - 1 ? 0 : 1);
                }
                else
                {
                    nextRow = row + (row == ROWS - 1 ? 0 : 1);
                    nextCol = col + (row == ROWS - 1 ? 1 : 0);
                }
                direction = !direction;
            }

            row = nextRow;
            col = nextCol;
        }

        return answer;
    }
};
