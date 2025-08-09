#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

/*
 * Goal: Check whether is it possible to partition to k subset with equal sum
 *
 * Intuition:
 * Since need equal sum so we can simply just divide by k.
 * And then sort it descendingly because we will be easier to break it out if cannot partiion into k
 * Then we just simply dfs and backtracking to check
 * Time Complexity: O(k * 2^n) --> At every index we can choose to include it or nott and then we also have k loop
 * */

class Solution
{
  public:
    bool canPartitionKSubsets(std::vector<int> &nums, int k)
    {
        int ttlSum{std::accumulate(nums.begin(), nums.end(), 0)};

        if (ttlSum % k != 0)
            return false;

        int sum{ttlSum / k};
        std::sort(nums.begin(), nums.end(), [](const int &A, const int &B) { return A > B; });

        std::vector<int> subset(k, 0);

        std::function<bool(const int &)> dfs_backtracking = [&](const int &index) {
            if (index == nums.size())
                return true;

            for (int i{}; i < k; i++)
            {
                if (subset[i] + nums[index] <= sum)
                {
                    subset[i] += nums[index];

                    if (dfs_backtracking(index + 1))
                        return true;

                    // backtracking
                    subset[i] -= nums[index];
                }

                if (subset[i] == 0)
                    return false;
            }
            return false;
        };
        return dfs_backtracking(0);
    }
};
