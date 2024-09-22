#include <cmath>
#include <ios>
#include <iostream>
#include <vector>

/*
 * Given an array of points
 * Goal: Return the k cloest points to the origin
 *
 * Intuition: Since we want to find the closst point to the origin and kth
 * smallest First we need to compute the distance from the point to the origin
 * Need a data structure that stored distance in ascending order
 * A clever way is to make use of the sort function, we can create our own
 * comparator function
 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 *
 * */
class Solution {
public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points,
                                         int k) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // sort it in ascending order
    std::sort(points.begin(), points.end(),
              [](const auto &p1, const auto &p2) {
                return (pow(p1[0], 2) + pow(p1[1], 2)) <
                       (pow(p2[0], 2) + pow(p2[1], 2));
              })

        // then resizes it because we only want k smallest
        points.resize(k);

    return points;
  }
};
