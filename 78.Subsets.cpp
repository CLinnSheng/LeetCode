/*
Goal: Return a list of subset
Constraint: Must not contain duplicate subsets
Intuition: Use dfs and backtracking
Time Complexity: O(2^n) this is because we have two choices for each number so
in total will be 2^n times Space Complexity: O(2^n)
*/
class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::size_t size = nums.size();
    if (size == 0)
      return {{}};

    std::vector<std::vector<int>> ans;
    std::vector<int> subset;

    std::function<void(int)> dfs = [&](int index) {
      ans.emplace_back(subset);

      for (int i = index; i < size; i++) {
        subset.emplace_back(nums[i]);
        dfs(i + 1);
        subset.pop_back();
      }
    };

    dfs(0);

    return std::move(ans);
  }
};
