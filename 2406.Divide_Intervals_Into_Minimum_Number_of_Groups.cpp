#include <algorithm>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

/*
 * Goals: Return the minimum number of groups need to make such that each
 * intervals is exactly in one group and no 2 intervals are in the same group
 * intersecting one another Intuition: Since there is an entering point &
 * leaving point. --> Line Sweeping algorithm If we draw a line in any point of
 * time, the number of intersections is equal to the minimum number of group we
 * needed to seperate the interval such that they are not in the same group So,
 * when we enter an interval +1 & leaving -1 NOTE: When the 2 intervals
 * intersect if there is at least one common number between them. eg [1, 5] &
 * [5, 8] intersects/ So the way we handle the case is we consider the enter
 * point first & then only proceed to the ending point
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  int minGroups(std::vector<std::vector<int>> &intervals) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<std::pair<int, int>> events;
    for (const auto &interval : intervals) {
      events.emplace_back(interval[0], 1);
      events.emplace_back(interval[1], -1);
    }

    std::sort(events.begin(), events.end(),
              [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
                if (a.first == b.first)
                  return a.second > b.second;

                return a.first < b.first;
              });

    int maxIntersections = 0;
    int currPts = 0;
    for (const auto &[time, pts] : events) {
      if (pts == 1)
        currPts++;
      else
        currPts--;
      maxIntersections = std::max(maxIntersections, currPts);
    }
    return std::move(maxIntersections);
  }
};
