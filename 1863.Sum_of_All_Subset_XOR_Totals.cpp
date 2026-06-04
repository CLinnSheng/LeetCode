#include <functional>
#include <vector>
/*
 * Find the sum of all the XOR of the subset
 * Hint: All possible subset --> Either choose or skip
 * So this is a backtracking problem
 *
 * Time Complexity: O(2^n * n) --> Total Subset: O(2^n) & O(n) operation for each subset
 * Spaec Complexity: O(n)
 * */
class Solution
{
  public:
    int subsetXORSum(std::vector<int> &nums)
    {
        int ans;
        std::vector<int> subset;

        std::function<void(std::vector<int> &, const int)> backtracking = [&](std::vector<int> &currSubset,
                                                                              const int index) {
            int sum{};
            // O(n)
            for (const auto num : currSubset)
            {
                sum ^= num;
            }
            ans += sum;

            // Base Case
            if (index == nums.size())
            {
                return;
            }

            for (int i{index}; i < nums.size(); i++)
            {
                // Include it
                currSubset.emplace_back(nums[i]);
                backtracking(currSubset, i + 1);

                // Pop it
                currSubset.pop_back();
            }
        };

        backtracking(subset, 0);
        return ans;
    }
};
