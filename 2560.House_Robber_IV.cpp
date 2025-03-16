#include <algorithm>
#include <climits>
#include <functional>
#include <vector>

/*
 * Constraint: Cannot steal from adjacent homes.
 * Capability: Maximum amount of money he stals from one house of all the houses he robbed.
 * Given an integer k, representing the minimum number of houses the robber will steal from
 *
 * Goal: Return the minimum capability of the robber out of all possible ways to steal at least k houses
 *
 * Intuition:
 * Actually we dont have to bother with k. We just need to rob k houses is enough.
 * Because if we rob more than k houses, we only increases the chance of robbing house with more money as the capability
 * is the maximum amount of money from all the houses get robbed. This is actually a tree decision problem, at every
 * house we can choose to rob or not. This will 2^n we can further optimize it by using memoziation then O(n^2)
 * */
class Solution
{
  public:
    int minCapability(std::vector<int> &nums, int k)
    {

        // top down approach (recursive + memoziation)
        // TLE
        // std::vector<std::vector<int>> cache(nums.size(), std::vector<int>(k + 1, -1));
        // std::function<int(const int &, const int &)> backtrack = [&](const int &index, const int &numHouse) {
        //     if (index >= nums.size())
        //     {
        //         if (numHouse)
        //             return INT_MAX;
        //         return 0;
        //     }
        //
        //     if (cache[index][numHouse] != -1)
        //         return cache[index][numHouse];
        //
        //     // include
        //     // at here we will be computing the capability by getting the house with the most amount of money
        //     int res1 = std::max(nums[index], backtrack(index + 2, numHouse - 1));
        //     // not include
        //     int res2 = backtrack(index + 1, numHouse);
        //
        //     int answer = std::min(res1, res2);
        //
        //     return cache[index][numHouse] = answer;
        // };
        // return backtrack(0, k);

        // bottom up (dp)
        // TLE
        // int n(nums.size());
        // std::vector<int> prev(n + 2, INT_MAX);
        //
        // for (int i{n - 1}; i >= 0; i--)
        //     prev[i] = std::min(nums[i], prev[i + 1]);
        //
        // for (int j{k}; j >= 2; j--)
        // {
        //     std::vector<int> cur(n + 2, INT_MAX);
        //     for (int i{n - 1}; i >= 0; i--)
        //     {
        //         // include
        //         auto res1{std::max(nums[i], prev[i + 2])};
        //         // not include
        //         auto res2 = cur[i + 1];
        //         cur[i] = std::min(res1, res2);
        //     }
        //     prev = cur;
        // }
        // return prev[0];

        // Binary Search
        // Search through a search space
        // Greadily check if a given capability is possible and based on it, shrink the search space
        // NOTE: PROBLEMS THAT REQUIRE MAXIMIZING THE MINIMUM OR MINIMIZING THE MAXIMUM OFTEN SUGGEST A BINARY SEARCH
        // ALGORITHM

        // We can actually observe that there is a search space from the problem statement, minimum capability
        // So the search space will simply be [min(nums), max(nums)]

        auto it_min{std::min_element(nums.begin(), nums.end())}, it_max{std::max_element(nums.begin(), nums.end())};
        int answer{};
        int left{*it_min}, right{*it_max};

        // helper function to find is it possible k houses that is less than or equal to this capability
        // u might wonder that we are finding minimum capability right, why do we need to consider less than it
        // because capability means that the maximum amount from all those houses got robbed
        // so the capability here in this function will be the maximum and finding the number of houses we can robbed
        // that are less than or equal to it while the capability value here will still be the same
        std::function<bool(const int &)> helper = [&nums, &k](const int &capability) {
            int i{}, count{};

            while (i < nums.size())
            {
                if (nums[i] <= capability)
                {
                    i += 2;
                    count++;
                }
                else
                    i++;

                if (count == k)
                    return true;
            }
            return count == k;
        };

        // O(nlgm)
        while (left <= right)
        {
            int m{left + (right - left) / 2};

            if (helper(m))
            {
                answer = m;
                right = m - 1;
            }
            else
                left = m + 1;
        }
        return answer;
    }
};
