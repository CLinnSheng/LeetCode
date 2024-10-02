#include <ios>
#include <iostream>
#include <vector>

/*
 * Given an integer array nums. Each element in the array represents your
 * maximum jump length at that position Goal: Return true if able to reach the
 * last index
 *
 * Intuition:
 * 1. Naive approahc by using double loop which is very costly
 * 2. Second way is more clever since we want to know are we able to reach the
 * final index or not why note we just straight away start from final index - 1,
 * check from final index - 1 are we able to reach the last index (keep
 * updating) This will reduce the time complexity to O(n) Space complexity: O(1)
 * */
class Soltuion {
public:
  bool canJump(std::vector<int> &nums) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int len = nums.size();
    if (len == 0)
      return true;

    int last_index = len - 1;
    for (int i = len - 2; i >= 0; i--) {
      if (nums[i] > last_index - index)
        last_index = i;
    }
    return last_index == 0;
  }
};
