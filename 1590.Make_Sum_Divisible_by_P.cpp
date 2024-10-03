#include <climits>
#include <cstdint>
#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>

/*
 * Goal: Delete the smallest size of subarray so that it is divisible by k
 * Intuition: Brute force jsut use double loop to see whether can it divisible
 * by k or not and then subtract it from the size of nums this will be O(n^2)
 *
 * We can optimize it to linear time by using prefix sum
 * So the intuition behind is we just need to remove the number which ttl_sum
 * mod by p but how do we find it, the way we use it is by computing the prefix
 * at every index and then find the complement of the index. If we can find the
 * complement of the index then we can find out the subarray we want to remove
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  int minSubarray(std::vector<int> &nums, int p) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int sum = 0;
    for (const auto &num : nums)
      sum = (sum + num) % p;

    auto remainder = sum % p;
    if (remainder == 0)
      return 0;

    std::unordered_map<int, int> map;
    map[0] = -1;

    int len = nums.size(), curr_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      curr_sum = (curr_sum + nums[i]) % p;
      auto complement = (curr_sum - remainder + p) % p;

      if (map.count(complement))
        len = std::min(len, i - map[complement]);

      map[curr_sum] = i;
    }
    return len == nums.size() ? -1 : len;
  }
};
