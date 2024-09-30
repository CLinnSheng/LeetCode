// Time Complexity: O(nlgn + 2^n)
// Space Complexity: O(2^N)
class Solution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int size = nums.size();
    if (size == 0)
      return {{}};

    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ans;
    std::vector<int> subset;

    std::function<void(int)> dfs_backtracking = [&](int index) {
      ans.emplace_back(subset);

      for (int i = index; i < size; i++)
        if (i == index || nums[i] != nums[i - 1]) {
          subset.emplace_back(nums[i]);
          // dfs
          dfs_backtracking(i + 1);
          // backtrack
          subset.pop_back();
        }
    };
    dfs_backtracking(0);
    return std::move(ans);
  }
};
