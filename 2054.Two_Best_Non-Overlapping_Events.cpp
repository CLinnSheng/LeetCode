#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

/*
 * Goal: Return the maximum Sum
 * 2d array where events[i] = (start, end, values)
 * You can choose at most two non-overlapping events such that their sum is
 * maximimized
 *
 * Intuition:
 * 1. By naive approach first we sort the array events by their starting time
 * and then try every single possible combination where it doesnt overlapping
 * Time Complexity: O(n^2)
 *
 * 2. How can we optimize by naive approach?
 * Notice that we traverse the evnts in ascending order in terms of starting
 * time So we dont really have to try every single events for each event, we
 * only have to try of those combination that is possible then we can make use
 * of heap to try the combination that is only possible
 * We can actually works backward to find the best event before the current
 * event since all the previous event is place in the heap and we can use a
 * variable to track the best val before the current event so that we dont
 * always have to push the event back to the heap agn
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 * NOTE: Start time and ending time are inclusive where you cannot attend 2
 * events where one of it starts and then the other end at the same time
 *
 * */
class Solution {
public:
  int maxTwoEvents(std::vector<std::vector<int>> &events) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        minHeap;
    int maxSum{}, maxVal{};

    // O(nlgn)
    std::sort(events.begin(), events.end());

    // O(n)
    for (const auto &event : events) {

      // O(lgn)
      while (!minHeap.empty() && event[0] > minHeap.top().first) {
        maxVal = std::max(maxVal, minHeap.top().second);
        minHeap.pop();
      }

      maxSum = std::max(maxSum, maxVal + event[2]);
      minHeap.push(std::make_pair(event[1], event[2]));
    }

    return maxSum;
  }
};
