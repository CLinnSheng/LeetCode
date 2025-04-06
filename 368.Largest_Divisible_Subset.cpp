#include <algorithm>
#include <functional>
#include <vector>

/*
 * Goal: Return the largest subset such that every pair (answer[i], answer[j]) statisfies this conditoin:
 * i. answer[i] % answer[j] == 0
 * ii. answer[j] % answer[i] == 0
 *
 * Intuition:
 * Whenever i see "subset" i can straight away know it must be tree decision problem that can solve naively through
 * recursive and optimize it through caching and further by dp. First let's dive into the question Every pair of element
 * must be divisible by one another So for every element, we can either choose or not choose to involve in the subset
 * When we choose we have to make sure the new element added is divisble by all other elements in th subarray.
 * But like this isnt very inefficient since just the choosing part already 2^n and this checking will take n^2 at
 * worst. Can we optimize it? Yes if u think how maths work if x is divisible by y and z is divisible by x. then z is
 * divisible by y. Eg: 2, 4, 8. 4 % 2 = 0 & 8 % 4 = 0 --> 8 % 2 = 0
 * Since the array is not in ascending order, so we have to sort it first
 * So without chaching the time complexity iwll be nlgn + 2^n witch caching can improve to n^2
 * And also you might wonder will the space compelxity over? actually not it will still be same n^2 because the maximum
 * length is 1000 so at worst the subarray also 1000
 * */
class Solution
{
  public:
    std::vector<int> largestDivisibleSubset(std::vector<int> &nums)
    {
        // top-down approach
        // sort
        // std::sort(nums.begin(), nums.end());
        // std::vector<int> answer{};
        //
        // // caching
        // // cache[i] stands for the maximum length ending at i including nums[i]
        // std::vector<int> cache(nums.size(), -1);
        //
        // std::function<void(const int &, std::vector<int>, const int &)> dfs_backtracking =
        //     [&](const int &index, std::vector<int> currSubset, const int &prev) {
        //         // base case, if new subset is longer
        //         if (currSubset.size() > answer.size())
        //         {
        //             answer = currSubset;
        //         }
        //
        //         for (int i{index}; i < nums.size(); i++)
        //         {
        //             // instead of branching out as 2, we here trying out all possible position
        //             if ((int)currSubset.size() + 1 > cache[i] && nums[i] % prev == 0)
        //             {
        //                 cache[i] = currSubset.size() + 1;
        //                 currSubset.push_back(nums[i]);
        //
        //                 // dfs on this currsubset
        //                 dfs_backtracking(i + 1, currSubset, nums[i]);
        //
        //                 // backtracking
        //                 currSubset.pop_back();
        //             }
        //         }
        //     };
        // dfs_backtracking(0, std::vector<int>{}, 1);
        // return answer;

        // bottom up approach
        std::sort(nums.begin(), nums.end());
        // initially all subset length is 1 which is including it self
        // dp[i] is the length of the subset ending at i including i which is the same as top down appraoch
        std::vector<int> dp(nums.size(), 1), prev(nums.size(), -1);
        int maxIdx{}; // tracking the last index of the largest subset

        for (int i{1}; i < nums.size(); i++)
            for (int j{}; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }

                if (dp[i] > dp[maxIdx])
                    maxIdx = i;
            }

        std::vector<int> answer{};
        for (int i{maxIdx}; i >= 0; i = prev[i])
        {
            answer.emplace_back(nums[i]);
            if (prev[i] == -1)
                return answer;
        }

        return answer;
    }
};
