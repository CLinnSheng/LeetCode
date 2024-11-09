#include <algorithm>
#include <climits>
#include <cstddef>
#include <vector>

/*
 * Goal: Return the sum of three integers that is closest to target
 *
 * Intuition: Sort the integer first and then use 3pointer with 1 poitner fixed
 * at 1 position Then keep iterate through to find the sum closes to the integer
 *
 * Time Complexity: O(n)
 * Space Cmpelxity: O(1)
 * */
class Solution {
public:
  int threeSumClosest(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int ans{INT_MAX / 2};

    std::size_t size(nums.size());
    if (size == 3)
      return nums[0] + nums[1] + nums[2];

    for (int i{}; i < size; i++) {
      int start{i + 1}, end(size - 1);

      while (start < end) {
        int currSum{nums[i] + nums[start] + nums[end]};
        ans =
            std::abs(target - currSum) < std::abs(target - ans) ? currSum : ans;

        if (currSum > target)
          end--;
        else if (currSum < target)
          start++;
        else
          return std::move(currSum);
      }
    }
    return std::move(ans);
  }
};
