#include <functional>
#include <vector>

/*
 * Goal: Find the number of subsets which has the maximum bitwise OR
 *
 * Intuition: First iterate through the array to find the maximum bitwise OR
 * And then dfs the array whether to include or not include the subsets
 * Time Complexity: O(2^n) because of whether include or not include
 * Space Complexity: O(n) at maximum the recursive call stack will be n only
 *
 * We can optimize it by using dp because we can see overlapping subproblem
 * this can greatly reduce the tiem compelxity to O(n*maxOR) & space complexity
 * will increase to O(n*maxOR)
 * */
class Solution {
public:
  int countMaxOrSubsets(std::vector<int> &nums) {

    int maxOR = 0;
    for (const auto &num : nums)
      maxOR |= num;

    int n = nums.size();
    std::vector<std::vector<int>> memo(n, std::vector<int>(maxOR + 1, -1));

    std::function<int(const int, const int)> dfs = [&](const int index,
                                                       const int currOR) {
      // base case we do not stop at once currOR equal to maxOR
      // because of if currOR is 5 which also equal to maxOR and then we add any
      // elements back in the subset which is also equal to maxOR
      if (index == nums.size())
        return (currOR == maxOR) ? 1 : 0;

      if (memo[index][currOR] != -1)
        return memo[index][currOR];

      // Include this number and not include this number
      return memo[index][currOR] =
                 dfs(index + 1, currOR | nums[index]) + dfs(index + 1, currOR);
    };

    return dfs(0, 0);
  }
};
