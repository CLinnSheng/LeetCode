#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
/*
 * Check whether the array can be divided into k non-empty subsets where sums are all equal
 *
 * Since it mention about subset so the order doesnt matter
 * There will be only 1 possible sum of the subarray because we have to divided into k.
 * In which ttlSum / k
 * Every index we can either choose to include it or not and finding all possible subset. This lead to backtracking.
 * So instead of thinking of include or not include it. We think of putting into a bucket so we can try all possible
 * path So to make thing easier we will sort the array first
 *
 * Time Complexity: O(k * 2^n)
 * where k is the number of bucket
 * and we have 2^n possible number of combination and each combination will try to palce into k buckets/k ways
 * */
class Solution
{
  public:
    bool canPartitionKSubsets(std::vector<int> &nums, int k)
    {
        int ttl_sum = std::accumulate(nums.begin(), nums.end(), 0);

        // Base Case where the total sum must be divided by k
        if (ttl_sum % k)
        {
            return false;
        }

        int sum{ttl_sum / k};

        // Since each subarray sum must equal to that 'sum'
        // Then we can sort it descendingly, and then prune it early by just checking whether is it greater than the sum
        std::sort(nums.begin(), nums.end(), [](const int A, const int B) { return A > B; });
        std::vector<int> buckets(k, 0);

        std::function<bool(const int)> backtracking = [&](const int index) {
            // Base Case
            if (index == nums.size())
            {
                return true;
            }
            // Pruning
            if (nums[index] > sum)
            {
                return false;
            }

            for (int i{}; i < k; i++)
            {
                // Try to put into each bucket
                if (buckets[i] + nums[index] > sum)
                {
                    continue;
                }

                buckets[i] += nums[index];
                if (backtracking(index + 1))
                {
                    return true;
                }

                // Backtracking
                buckets[i] -= nums[index];

                // Handle cases after dfs down to the leaf, still unable to aplce into empty backet
                // means that it is impossible to form k subset with the equal sum.
                // Because the result will stil be the same if we put into bucket 2 or bucket 3
                if (buckets[i] == 0)
                {
                    break;
                }
            }

            return false;
        };
        return backtracking(0);
    }
};
