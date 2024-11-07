#include <vector>
/*
 * Goal: Return the size of the largest combination of candidates with a bitwise
 * AND & greater than 1
 *
 * Intuition: The number can be randomly chosen from the array & dun have to be
 * consecutive. It can be any random combination. So we need to check by index
 * for every candidate in the array
 *
 * Time Complexity: O(32 * n)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  int largestCombination(std::vector<int> &candidates) {
    int ans{};

    for (int i{}; i < 32; i++) {
      int cnt{};
      for (int candidate : candidates)
        if (candidate & (1 << i))
          cnt++;

      ans = std::max(ans, cnt);
    }

    return std::move(ans);
  }
};
