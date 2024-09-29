#include <cstddef>
#include <functional>
#include <ios>
#include <iostream>
#include <vector>

/*
 * Goal: Return all possible permutations
 * Intuition: Can use dfs and backtracking and have a checking list to check
 * which number has already included
 * Time Complexity: O(n * n!) the reason of n! is because the number of
 * permutations of size n is n! and then we going through every single element
 * so we times it with n Space Complexity: O(n * n!) because of the recursive
 * call stack function we call n * n! times as well
 * */
class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::size_t size = nums.size();
    if (size == 0)
      return {{}};

    std::vector<std::vector<int>> ans;
    std::vector<int> subset;
    std::vector<bool> checking(size, false);

    std::function<void(void)> dfs_backtracking = [&]() {
      if (subset.size() == size) {
        ans.emplace_back(subset);
        return;
      }

      for (int i = 0; i < size; i++) {
        if (checking[i])
          continue;

        // dfs
        subset.emplace_back(nums[i]);
        checking[i] = true;

        dfs_backtracking();

        // backtracking
        subset.pop_back();
        checking[i] = false;
      }
    };

    dfs_backtracking();
    return std::move(ans);
  }
};
