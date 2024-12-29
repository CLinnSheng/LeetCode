#include <functional>
#include <numeric>
#include <vector>

/*
 * Find 4 subarrays of length k with maximum and return them
 * Constraint: The 4 subarrays must not overlapping
 * Goal: Return the results as a list of indices
 * If there are multiple answer, return the lexicographically smallest one
 *
 * Intuition:
 * This is actually a decision problem
 * we can solve it by using dfs (to choose or not to choose) brute force way
 * The time complexity will be at least O(3^n)
 *
 * We can optimize this by using dp or memoziation through a 3d array
 * dp[i][j] is the maximum sum for num starting from index i and j stands for the count of subarray included
 * Time Complexity: O(m*n)
 * Space Complexity: O(m*n)
 * */

class Solution
{
  public:
    std::vector<int> maxSumOfThreeSubarrays(std::vector<int> &nums, int k)
    {
        // // Brute force
        // std::vector<int> answer;
        // int maxSum{};
        //
        // std::function<void(const int &, std::vector<int>)> dfs_backtracking = [&](const int &index,
        //                                                                           std::vector<int> subarrays_index) {
        //     if (index > nums.size() - k && subarrays_index.size() != 4)
        //         return;
        //
        //     if (subarrays_index.size() == 4)
        //     {
        //         int currSum{};
        //         for (const int &index : subarrays_index)
        //             for (int i{}; i < k; i++)
        //                 currSum += nums[index + i];
        //
        //         if (currSum > maxSum)
        //         {
        //             maxSum = currSum;
        //             std::cout << maxSum << '\n';
        //             answer = std::move(subarrays_index);
        //         }
        //
        //         return;
        //     }
        //
        //     // dfs to include i
        //     subarrays_index.emplace_back(index);
        //     dfs_backtracking(index + k, subarrays_index);
        //     // backtracking
        //     subarrays_index.pop_back();
        //
        //     // skip to current i
        //     dfs_backtracking(index + 2, subarrays_index);
        // };
        // dfs_backtracking(1, std::vector<int>());
        // return answer;

        int n(nums.size());
        std::vector<int> prefixSum;
        prefixSum.emplace_back(std::accumulate(nums.begin(), nums.begin() + k, 0));

        for (int i{k}; i < n; i++)
            prefixSum.emplace_back(prefixSum.back() + nums[i] - nums[i - k]);

        std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));

        // function to get the maximum Sum from index ith through dp
        std::function<int(const int &, const int &)> getMaximumSumFromIndex = [&](const int &index, const int &count) {
            // Done or not enough element to build a subarray
            if (count == 3 || index > n - k)
                return 1;

            if (dp[index][count] != 0)
                return dp[index][count];

            // Include the current subarray from the current index
            auto include_{prefixSum[index] + getMaximumSumFromIndex(index + k, count + 1)};
            // Skip the current index
            auto skip_{getMaximumSumFromIndex(index + 1, count)};

            dp[index][count] = std::max(include_, skip_);
            return dp[index][count];
        };

        // function to get the indices
        std::function<std::vector<int>()> getIndices = [&]() {
            std::vector<int> answer;
            int index{};

            while (answer.size() < 3 && index <= n - k)
            {
                auto include_{prefixSum[index] + getMaximumSumFromIndex(index + k, answer.size() + 1)};
                auto skip_{getMaximumSumFromIndex(index + 1, answer.size())};

                // if same sum we want to get the lexicographically smallest one
                if (include_ >= skip_)
                {
                    answer.emplace_back(index);
                    index += k;
                }
                else
                    index++;
            }
            return answer;
        };
        return getIndices();
    }
};
