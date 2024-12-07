#include <cmath>
#include <vector>

/*
 * Goal: Return the minimum possible penalty after performing the operations.
 * Penailty: Maximum number of balls in a bag (Trying to minimize the penalty
 * after the operations)
 *
 * Intuition:
 * We can use binary search on the possible range of penalty
 * So we need to find out the upper and lower bound of upper bound
 * then try use binary search and see whether is it possible to split it less
 * than or equal to maxOperations
 * Time Complexity: O(nlgk)
 * Space Complexity: O(1)
 * */
class Solution {
public:
  int minimumSize(std::vector<int> &nums, int maxOperations) {
    int min{1};
    int max{};

    for (const auto &num : nums)
      max = std::max(max, num);

    // O(lgk)
    while (min < max) {

      int middle = min + (max - min) / 2;

      // O(n)
      if (helper(middle, maxOperations, nums))
        max = middle;
      else
        min = middle + 1;
    }

    return min;
  }

  bool helper(const int &middle, const int &maxOperations,
              const std::vector<int> &nums) {
    int numberOperations{};

    for (const auto &num : nums) {
      int operation = std::ceil(num / (double)middle) - 1;
      numberOperations += operation;

      if (numberOperations > maxOperations)
        return false;
    }
    return true;
  }
};
