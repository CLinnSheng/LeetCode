#include <vector>

/*
 * Goal: Return the number of unoccupied cells that are not guarded
 * Each guard can see in 4 directions but there exists wall in the map
 *
 * Intuition: We will build the map first and then place the wall and guard into
 * the map A guard can see every cell in 4 directions & can get be blocked by
 * wall So we will just simply stimulate it.
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 * */
class Solution
{
  public:
    enum STATE
    {
        UNGUARDED = 0,
        GUARDED,
        GUARD,
        WALL
    };

    int countUnguarded(int m, int n, std::vector<std::vector<int>> &guards, std::vector<std::vector<int>> &walls)
    {

        std::vector<std::vector<int>> map(m, std::vector<int>(n, STATE::UNGUARDED));

        for (const auto &guard : guards)
            map[guard[0]][guard[1]] = STATE::GUARD;

        for (const auto &wall : walls)
            map[wall[0]][wall[1]] = STATE::WALL;

        // Go to every row first
        for (int i{}; i < m; i++)
        {
            bool guard = false;
            // Look from the left
            for (int j{}; j < n; j++)
                if (map[i][j] == STATE::GUARD)
                    guard = true;
                else if (map[i][j] == STATE::WALL)
                    guard = false;
                else if (!map[i][j] && guard) // only take care of empty cooridnates, for other just
                                              // skip if it stay until the last condition
                    map[i][j] = STATE::GUARDED;
            guard = false;
            // Look from the right
            for (int j{n - 1}; j >= 0; j--)
                if (map[i][j] == STATE::GUARD)
                    guard = true;
                else if (map[i][j] == STATE::WALL)
                    guard = false;
                else if (!map[i][j] && guard) // only take care of empty cooridnates, for other just
                                              // skip if it stay until the last condition
                    map[i][j] = STATE::GUARDED;
        }

        // Go to every column
        for (int j{}; j < n; j++)
        {
            bool guard = false;
            // Look from above
            for (int i{}; i < m; i++)

                if (map[i][j] == STATE::GUARD)
                    guard = true;
                else if (map[i][j] == STATE::WALL)
                    guard = false;
                else if (!map[i][j] && guard) // only take care of empty cooridnates, for other just
                                              // skip if it stay until the last condition
                    map[i][j] = STATE::GUARDED;
            guard = false;
            // Look from bottom
            for (int i{m - 1}; i >= 0; i--)
                if (map[i][j] == STATE::GUARD)
                    guard = true;
                else if (map[i][j] == STATE::WALL)
                    guard = false;
                else if (!map[i][j] && guard) // only take care of empty cooridnates, for other just
                                              // skip if it stay until the last condition
                    map[i][j] = STATE::GUARDED;
        }
        int ans{};

        for (int i{}; i < m; i++)
            for (int j{}; j < n; j++)
                if (map[i][j] == STATE::UNGUARDED)
                    ans++;

        return ans;
    }
};
