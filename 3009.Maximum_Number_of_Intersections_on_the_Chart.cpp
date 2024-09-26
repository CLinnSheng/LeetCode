#include <cstdint>
#include <map>

/*
 * Goal: Find the maximum number of intersections points that a horizontal line
 * which extends infinitely in both directions.
 *
 * Intuition: The determine factor of interstion points is just the y
 * coordinates. So, we need to find all potential y values where intersection
 * count changes, which happen at or between 2 y-values By naive approach, we
 * need to check all possible y-values and this will be v tedious. To optimize
 * it, we only consider the y-values where changes occur.
 *
 * So we kinda divide the function or line or the graph into several segments
 * based on the coordinates & an then we drew all the segments in a horziontal
 * way stack by stack. And then draw a vertical line where it intersect the most
 * segments. But the hard part is how we gonna determine when the graph is
 * increasing or decreasing that will gonna affect how we drew the segments
 *
 * */
class Solution {
public:
  int maxIntersectionCount(std::vector<int> &y) {

    std::int32_t n_y = y.size();
    std::int32_t max_Intersection = 0, current_Intersection = 0;
    std::map<int, int> segments;

    for (int i = 1; i < n_y; i++) {
      // We double the coordinates in order to handle half-integer coordinates
      std::int32_t start = 2 * y[i - 1];
      // Add an adjustment of -1/1 to ensure porpoer ordering when lines meet at
      // endpoints, so that we dont doubele count int32_t eg: upward line
      // segment, we will -1 to ensure that the end of this segment will be
      // processed before the start of next process downward line segment, we
      // will add 1 to ensure that the end of this segment is processed after
      // the start of any segment ending at this y-coordinates
      std::int32_t end =
          2 * y[i] + (i == n - 1 ? 0 : (y[i] > y[i - 1] ? -1 : 1));

      // Use the lower coordinate of the current segment as the start regardless
      // of going up or down
      int &startCnt = segments[std::min(start, end)];
      startCnt++;

      // Use the higher coordinates as the end of the current segment & we + 1
      // to ensure that the end event comes after the start event
      int &endCnt = segments[std::max(start, end) + 1];
      endCnt--;
    }

    for (const auto &[_, cnt] : segments) {
      current_Intersection += cnt;
      max_Intersection = std::max(max_Intersection, current_Intersection);
    }

    return max_Intersection;
  }
};
