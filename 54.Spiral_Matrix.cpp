#include <utility>
#include <vector>

/*
 * Goal: Return all elements of the matrix in spiral order
 *
 * Intuition:
 * This is a graph problem, we can traverse it through dfs.
 * Mark every cell that is visited, so that we dont visit it again and then how do we travel?
 * Have a variable to keep tracking the direction. We change the direction whenever we couldnt travel
 * E -> S -> W -> N
 * */
class Solution
{
  private:
    std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        int ROWS(matrix.size()), COLS(matrix[0].size());
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
        std::vector<int> answer;
        int direction{}; // 0 - right, 1 - down, 2 - left, 3 - up
        int row{}, col{};

        while (answer.size() < ROWS * COLS)
        {
            answer.emplace_back(matrix[row][col]);
            visited[row][col] = true;

            int nxtRow{row + DIRECTIONS[direction].first};
            int nxtCol{col + DIRECTIONS[direction].second};

            // check whether we can move or not
            if (nxtRow < 0 || nxtCol < 0 || nxtRow >= ROWS || nxtCol >= COLS || visited[nxtRow][nxtCol])
            {
                // change direction
                direction = (direction + 1) % 4;
                nxtRow = row + DIRECTIONS[direction].first;
                nxtCol = col + DIRECTIONS[direction].second;
            }

            row = nxtRow;
            col = nxtCol;
        }
        return answer;
    }
};
