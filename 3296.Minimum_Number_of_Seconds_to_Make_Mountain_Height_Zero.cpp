/*
 * This question is similar to 875. Koko eating bananas
 *
 * Take Note: The workers work simultaneously to reduce the height of the
 mountain. For worker i:

    To decrease the mountain's height by x, it takes workerTimes[i] +
 workerTimes[i] * 2 + ... + workerTimes[i] * x seconds. For example: To reduce
 the height of the mountain by 1, it takes workerTimes[i] seconds. To reduce the
 height of the mountain by 2, it takes workerTimes[i] + workerTimes[i] * 2
 seconds, and so on.

  Intuition: Since there is a possiblity range of time where the height can be
 reduce to 0 from here we can apply binary serch from the range of time If they
 are able to make it in x time, then we will try to see whether a lower value
 than x can make it or not (finding the minimum) The range will be [1, 1e18]
  Derivation of Upper Bound:
  Consider the worst case only 1 worker in the array and the workerTimes[0] =
 1e6 & the maximum heigh of mountain is 1e5 Therefore the time taken will be
 1e6(1+2+3..+1e5) approximately equal to 1e16 Then apply binary search on this
 range
 The checking condition in doing binary search in the range of 1 to 1e16 is
 by keep checking if all the workers are able to reduce the height to 0
 in the time required which is mid
 * Goal: Return the minimum number of seconds required for the workers to make
 the height to 0
*/
#include <cstdint>
#include <ios>
#include <iostream>
class Solution {
public:
  long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::uint64_t lower_boundary = 0, upper_boundary = 1e16;
    std::uint64_t ans = 0;

    // This function check whether all the workers are able to reduce the height
    // to 0 in the time given which is times
    auto helper = [=](std::uint64_t times) {
      std::uint64_t time_taken = 0;

      for (const auto &time : workerTimes) {
        std::uint64_t left = 0, right = 1e6;

        while (left <= right) {
          auto mid = left + (right - left) / 2;
          if (time * mid * (mid + 1) / 2 <= times)
            left = mid + 1;
          else
            right = mid - 1;
        }
        // at here we add right because using left will overestimate the height
        // when break out of the loop
        time_taken += right;
        if (time_taken >= mountainHeight)
          return true;
      }

      return time_taken >= mountainHeight;
    };
    while (lower_boundary <= upper_boundary) {
      auto mid = lower_boundary + (upper_boundary - lower_boundary) / 2;
      if (helper(mid)) {
        upper_boundary = mid - 1;
        ans = mid;
      } else
        lower_boundary = mid + 1;
    }
    return lower_boundary;
  }
};
