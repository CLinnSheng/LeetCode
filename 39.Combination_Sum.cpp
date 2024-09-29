#include <functional>
#include <ios>
#include <iostream>
#include <vector>
/*
 * Goal: Return a list of all unique combinations of candidates where the chosen
 * number sum to target. Condition: Same number may be chosen from candidates an
 * unlimited number of times. Assume the list of vector is sorted
 *
 * Intuition: Since want to find the combination of sums equal to target
 * we can use dfs and backtracking when exceed the sums
 * Time Complexity: O(2^n) because there is n element and then we can either
 * chose it or not Space Complexity: O(2^n) if we go to the deepest then the
 * recursion stack will be at 2^n
 * */
class Solution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::vector<std::vector<int>> ans;
    std::vector<int> subset;

    std::function<void(const int &, int)> dfs_backtrack = [&](const int &index,
                                                              int curr_sum) {
      if (curr_sum == target) {
        ans.emplace_back(subset);
        return;
      }

      if (curr_sum > target)
        return;

      for (int i = index; i < candidates.size(); i++) {
        curr_sum += candidates[i];
        subset.emplace_back(candidates[i]);

        // dfs
        // the index still remain at i because we want to try and see whether
        // the same index can sum up to target or not
        dfs_backtrack(i, curr_sum);

        // backtracking
        curr_sum -= candidates[i];
        subset.pop_back();
      }
    };

    dfs_backtrack(0, 0);
    return std::move(ans);
  }
};
