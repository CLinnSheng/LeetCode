#include <functional>
#include <unordered_set>

class Solution
{
  public:
    int totalNQueens(int n)
    {
        if (!n)
            return 0;

        // A hash set to track the placed and restricted region
        std::unordered_set<int> cols, diagonal1, diagonal2;
        int answer{};

        std::function<void(const int &)> dfs_backtracking = [&](const int &row) {
            if (row == n)
            {
                answer++;
                return;
            }

            // Iterating through the columns of the specific row
            for (int c{}; c < n; c++)
            {
                // Checking
                if (cols.count(c) == 0 && diagonal1.count(c + row) == 0 && diagonal2.count(c - row) == 0)
                {
                    cols.insert(c);
                    // 2 direction of diagonal
                    diagonal1.insert(c + row);
                    diagonal2.insert(c - row);

                    dfs_backtracking(row + 1);

                    // backtracking
                    cols.erase(c);
                    diagonal1.erase(c + row);
                    diagonal2.erase(c - row);
                }
            }
        };
        dfs_backtracking(0);
        return answer;
    }
};
