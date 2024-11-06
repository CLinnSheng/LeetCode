#include <climits>
#include <vector>

/*
 * Goal: Find whether we can sort the array or not
 *
 * Intuition:
 * Use bubble sort to sort the array with some tweaks which is check the value
 * if we need to swap or not & after that check whether they have the same set
 * bit or not, in order to perform swap Constraint: We can swap the elements if
 * and only if both of them have the same number of set bits
 * In the end, the array will be sorted or if we encounter any swap needed but
 * couldn't perform and thus return false
 * Time Complexity: O(n^2) and omega(n)
 * Space Complexity: O(n)
 *
 * We can optimize this because we dont really need to perform the 'sorting',
 * because for a set of numbers with same set bit we know in the end it will be
 * sorted So for every subset with the same set bit will be sorted, then we need
 * to check if we combine whether they are sorted or not
 * We can do this by comparing the maxVal from the first set to the minVal of
 * the next set, continue until the last set.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * */
class Solution {
public:
  bool canSortArray(std::vector<int> &nums) {
    int currMax{nums[0]}, currMin{nums[0]};
    int prevMax{INT_MIN};

    for (int i{1}; i < nums.size(); i++) {
      // belongs to the same set
      if (__builtin_popcount(nums[i]) == __builtin_popcount(currMax)) {
        currMax = std::max(currMax, nums[i]);
        currMin = std::min(currMin, nums[i]);
      } else {
        if (prevMax > currMin)
          return false;
        prevMax = currMax;
        currMin = currMax = nums[i];
      }
    }

    // for the last set
    if (prevMax > currMin)
      return false;

    return true;
  }
};
