#include <algorithm>
#include <functional>
#include <vector>
/*
 * Find all the subset but not duplicate
 * So how do we handle duplicate?
 * Duplicate happends because of repeating of same element, to efficiently check repeating same element
 * Is to sort the nums first, then we can easily check its adjacent element to prevent duplciate Subset
 *
 * Time Complexiy: O(2^n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> subset;
        std::sort(nums.begin(), nums.end());

        std::function<void(const int)> backtracking = [&](const int index) {
            ans.emplace_back(subset);

            // Base Case
            if (index == nums.size())
            {
                return;
            }

            for (int i{index}; i < nums.size(); i++)
            {
                // Check for repeating element
                if (i > index && nums[i] == nums[i - 1])
                {
                    continue;
                }

                subset.emplace_back(nums[i]);
                backtracking(i + 1);
                subset.pop_back();
            }
        };

        backtracking(0);
        return ans;
    }
};
