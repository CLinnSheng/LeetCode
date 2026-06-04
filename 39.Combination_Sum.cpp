#include <functional>
#include <vector>
using std::vector;

/*
 * Find all the possible subset that sum up to target
 * One thing to note over here is we can use the same index multiple time
 * So the time complexity will be O(2^(t/m))
 * t is the target and m is minumum element in the array
 * The number of element get chosen is t/m
 * Since finding all the subset --> Backtracking
 * */
class Solution
{
  public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> subset;

        std::function<void(const int, const int)> backtracking = [&](const int index, const int currSum) {
            // Base case
            if (currSum == target)
            {
                ans.emplace_back(subset);
                return;
            }

            if (currSum > target || index == nums.size())
            {
                return;
            }

            for (int i{index}; i < nums.size(); i++)
            {
                // Include the current element
                subset.emplace_back(nums[i]);

                // Pass the same index because we are allow to use the same element
                backtracking(i, currSum + nums[i]);

                subset.pop_back();
            }
        };

        backtracking(0, 0);
        return ans;
    }
};
