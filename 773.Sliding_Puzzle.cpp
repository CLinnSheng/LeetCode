#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
/*
 * goal: return the least number of move so that the state of the board is
 * 1,2,3,4,5,0
 *
 * intuition: a swap can be move in 4 directions, so every index in the board
 * has a fixed number of moves. we can use dfs or bfsd to find out all possible
 * states and return the least number of moves required
 * Time Complexity: O(mn)! * mn where mn! is the number of possible
 * configurations & m*n is where every loop the possible adjacent is
 * upperbounded by mn Space Complexity: O(mn)!
 * */
class Solution {
public:
  const std::vector<std::vector<int>> DIRECTIONS{{1, 3}, {0, 2, 4}, {1, 5},
                                                 {0, 4}, {1, 3, 5}, {2, 4}};
  int slidingPuzzle(std::vector<std::vector<int>> &board) {
    std::unordered_set<std::string> visited;
    std::string starting;

    for (const auto &row : board)
      for (const auto &element : row)
        starting += std::to_string(element);

    std::deque<std::string> queue;
    queue.emplace_back(starting);
    visited.insert(starting);
    int moves{};

    while (!queue.empty()) {
      int size = queue.size();

      while (size > 0) {
        string currentState = queue.front();
        queue.pop_front();

        if (currentState == "123450")
          return moves;

        int zeroPos = currentState.find('0');
        for (int nextPos : DIRECTIONS[zeroPos]) {
          string nextState = currentState;
          std::swap(nextState[zeroPos], nextState[nextPos]);

          if (visited.count(nextState))
            continue;

          visited.insert(nextState);
          queue.emplace_back(nextState);
        }
        size--;
      }
      moves++;
    }

    return -1;
  }
};
