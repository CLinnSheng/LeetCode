/*
Given array robot where robot[i] is the position of the ith robot
Given 2d array factory where factory[i] = [position_i, limit_i] position_i is
the position of the ith factory and limit_i is the most robot ith factory it can
repair. Robot can move in 2directions

Goal: Return the minimum total distanced traveled by all the robots.

Intuition: Since want to get the minimum distance travel. For sure we need the
robot to move to the nearest factory. So we will sort the robot and factory
based on the position first. Then we will try to either assign or skip the
current index of the robot (try all possible combination of assignment). Time
Complexity: O(n*m) Space Complexity: O(n + m) recursion call stack

We can actually see overlapping subproblem, so we can optimize it by using
dynamic programming & the assignment of a robot also depends on the previous
robot Which is still O(n*m) but is more efficient than naive approach
*/
using ll = long long;

class Solution {
public:
  long long minimumTotalDistance(std::vector<int> &robot,
                                 std::vector<std::vector<int>> &factory) {
    std::sort(robot.begin(), robot.end());
    std::sort(factory.begin(), factory.end());

    std::vector<int> factoryPositions;
    for (const auto &f : factory)
      for (int i{}; i < f[1]; i++)
        factoryPositions.emplace_back(f[0]);

    // topdown dp
    // caching/memoziation
    // std::vector<std::vector<ll>> topdownDP(robot.size(),
    // std::vector<ll>(factoryPositions.size(), -1));

    // return helper(0, 0, robot, factoryPositions, topdownDP);

    // bottomup dp
    std::vector<std::vector<ll>> bottomupDP(
        robot.size() + 1, std::vector<ll>(factoryPositions.size() + 1, 0));

    // base case no factories left
    for (int i{}; i < robot.size(); i++)
      bottomupDP[i][factoryPositions.size()] = 1e12;

    for (int i = robot.size() - 1; i >= 0; i--)
      for (int j = factoryPositions.size() - 1; j >= 0; j--) {
        // same with topdown
        // there is 2 option whether assign the current factory or skip to the
        // next 1
        ll assign =
            abs(robot[i] - factoryPositions[j]) + bottomupDP[i + 1][j + 1];
        ll skip = bottomupDP[i][j + 1];

        bottomupDP[i][j] = std::min(assign, skip);
      }

    return bottomupDP[0][0];
  }
  // topDown approach
  //  ll helper(const int robotIndex, const int factoryIndex, const
  //  std::vector<int>& robot, const std::vector<int>& factoryPositions,
  //  std::vector<std::vector<ll>>& DP) {

  //     // Base case
  //     // no more robot left
  //     if (robotIndex == robot.size()) return 0;
  //     // no more factory left
  //     if (factoryIndex == factoryPositions.size()) return 1e12;

  //     // check whether we solve this before or not
  //     if (DP[robotIndex][factoryIndex] != -1) return
  //     DP[robotIndex][factoryIndex];

  //     // take the nearest factory which correspond to its index
  //     ll assign = abs(robot[robotIndex] - factoryPositions[factoryIndex]) +
  //     helper(robotIndex + 1, factoryIndex + 1, robot, factoryPositions, DP);

  //     // skip this and take the second factory nearest to him
  //     ll skip = helper(robotIndex, factoryIndex + 1, robot, factoryPositions,
  //     DP);

  //     return DP[robotIndex][factoryIndex] = std::min(assign, skip);
  // }
};
