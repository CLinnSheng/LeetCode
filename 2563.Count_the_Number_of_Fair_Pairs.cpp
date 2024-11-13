#include <algorithm>
#include <functional>
#include <vector>
using ll = long;

/*
 * Goal: return the number of fairs pairs within the boundary of lower & upper
 * A pair(i, j) is fair if
 *  -0 <= i < j < n
 *  -lower <= nums[i] + nums[j] <= upper
 *
 *  Intuition: The most straighaway is by using naive approach where we iterate
 * through the array and then another inner loop to check whether is this
 * current pair is fair pair or not Time Complexity: O(n^2)
 *
 *  We can optimize this but not having a double loop
 *  We just have to find out the boundary for each num in nums where it can form
 * a fair pair. The way to do this is first sort the array and then find out the
 * upper and lower boundary where the sum is within lwoer & upper
 * The upper boundary and lower boundary can be found from a sorted array by
 * using binary binarySearch Time Complexity: O(nlgn) Space Complexity: O(1)
 * */
class Solution {
public:
  ll countFairPairs(std::vector<int> &nums, int lower, int upper) {
    ll ans{};

    std::function<int(int, int, const int &)> binarySearch =
        [&nums](int left, int right, const int &target) {
          while (left <= right) {
            int middle(left + (right - left) / 2);

            if (nums[middle] >= target)
              right = middle - 1;
            else
              left = middle + 1;
          }
          return right;
        };

    std::sort(nums.begin(), nums.end());
    for (int i{}; i < nums.size(); i++)
      // the first 1 is finding the index of the maximum possible sum that is
      // smaller or equal to upper the second 1 is finding the index of the
      // largest possible sum that is smaller than the lower
      ans += binarySearch(i + 1, nums.size() - 1, upper - nums[i] + 1) -
             binarySearch(i + 1, nums.size() - 1, lower - nums[i]);

    return ans;
  }
};
