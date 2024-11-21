#include <functional>
#include <utility>
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
class Solution {
public:
  const int UNGUARDED{0};
  const int GUARDED{1};
  const int GUARD{2};
  const int WALL{3};

  int countUnguarded(int m, int n, std::vector<std::vector<int>> &guards,
                     std::vector<std::vector<int>> &walls) {

    std::vector<std::vector<int>> map(m, std::vector<int>(n, 0));

    for (const auto &guard : guards)
      map[guard[0]][guard[1]] = GUARD;

    for (const auto &wall : walls)
      map[wall[0]][wall[1]] = WALL;

    // Go to every row first
    for (int i{}; i < m; i++) {
      bool guard = false;
      for (int j{}; j < n; j++)
        if (map[i][j] == GUARD)
          guard = true;
        else if (map[i][j] == WALL)
          guard = false;
        else if (!map[i][j] &&
                 guard) // only take care of empty cooridnates, for other just
                        // skip if it stay until the last condition
          map[i][j] = GUARDED;
      guard = false;
      for (int j{m - 1}; j >= 0; j--)
        if (map[i][j] == GUARD)
          guard = true;
        else if (map[i][j] == WALL)
          guard = false;
        else if (!map[i][j] &&
                 guard) // only take care of empty cooridnates, for other just
                        // skip if it stay until the last condition
          map[i][j] = GUARDED;
    }

    // Go to every column
    for (int j{}; j < n; j++) {
      bool guard = false;
      for (int i{}; i < m; i++)

        if (map[i][j] == GUARD)
          guard = true;
        else if (map[i][j] == WALL)
          guard = false;
        else if (!map[i][j] &&
                 guard) // only take care of empty cooridnates, for other just
                        // skip if it stay until the last condition
          map[i][j] = GUARDED;
      guard = false;
      for (int i{m - 1}; i >= 0; i--)
        if (map[i][j] == GUARD)
          guard = true;
        else if (map[i][j] == WALL)
          guard = false;
        else if (!map[i][j] &&
                 guard) // only take care of empty cooridnates, for other just
                        // skip if it stay until the last condition
          map[i][j] = GUARDED;
    }
    int ans{};

    for (int i{}; i < m; i++)
      for (int j{}; j < n; j++)
        if (map[i][j] == UNGUARDED)
          ans++;

    return ans;
  }
};
