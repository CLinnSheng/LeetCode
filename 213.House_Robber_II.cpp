#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>

/*
 * Derived from the House Robber Question
 * Constraint: The housese are in a circle that means the first house and the
 * last house is connected So we cannot visit the first and last house So now
 * our choice is limited either we visit choose from n[1] to n[n - 1] or from
 * n[2] to n[n]
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  int rob(std::vector<int> &nums) {

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::int32_t n_house = nums.size();

    if (n_house == 0)
      return 0;
    if (n_house == 1)
      return nums[0];
    if (n_house == 2)
      return std::max(nums[0], nums[1]);
    // range [1, n-1]
    std::vector<int> copy_1 = nums;
    copy_1[1] = std::max(copy_1[0], copy_1[1]);

    for (int i = 2; i < n_house - 1; i++)
      copy_1[i] = std::max(copy_1[i - 1], copy_1[i] + copy_1[i - 2]);

    // range[2, n]
    std::vector<int> copy_2 = nums;
    copy_2[2] = std::max(copy_2[2], copy_2[1]);

    for (int i = 3; i < n_house; i++)
      copy_2[i] = std::max(copy_2[i - 1], copy_2[i] + copy_2[i - 2]);

    return std::max(copy_2[n_house - 1], copy_1[n_house - 2]);
  }
};
