#include <algorithm>
#include <functional>
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
    if (nums.size() == 1)
      return nums[0];

    std::function<int(const std::vector<int> &)> helper =
        [](const std::vector<int> &n) {
          if (n.empty())
            return 0;
          if (n.size() == 1)
            return n[0];

          std::vector<int> dp(n.size());
          dp[0] = n[0];
          dp[1] = std::max(n[0], n[1]);

          for (int i{2}; i < n.size(); i++)
            dp[i] = std::max(dp[i - 1], dp[i - 2] + n[i]);

          return dp.back();
        };
    // either startin from the first 1 or the second 1
    // first 1 is from [1, n - 1] while second is from [2, n]
    return std::max(helper(std::vector<int>(nums.begin(), nums.end() - 1)),
                    helper(std::vector<int>(nums.begin() + 1, nums.end())));
  }
};
