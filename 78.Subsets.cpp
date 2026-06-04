#include <functional>
#include <vector>
using std::vector;

/*
 * Finding all the possible subset include empty 1
 * At each index we either choose or not choose. O(2^n)
 * Since we are getting all the possible subsset, backtracking will be the algo to solve this to get all the possible
 * subset
 *
 * Time Complexity: O(2^n * n)
 * Total Subset -> O(2^n) & Each subset tree do n operation O(n)
 * Space Complexity: O(n)
 * */

class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.empty())
        {
            return {};
        }

        vector<int> subset;
        vector<vector<int>> ans;
        int index{};

        std::function<void(const int)> backtracking = [&](const int index) {
            // Push the subset
            ans.emplace_back(subset);

            // Base Case
            if (index == nums.size())
            {
                return;
            }

            // O(n)
            for (int i{index}; i < nums.size(); i++)
            {
                // New subset
                subset.emplace_back(nums[i]);
                backtracking(i + 1);

                // Backtrack
                subset.pop_back();
            }
        };

        backtracking(index);
        return ans;
    }
};
