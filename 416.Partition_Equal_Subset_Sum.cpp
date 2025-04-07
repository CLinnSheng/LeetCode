#include <functional>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Goal: Return true if you can partition the array into 2 subset such that the sum in both subsets s equal or false
 * otherwise
 *
 * Intuition:
 * Find "subset" immediately know is a tree decision problem. So at every index we can either choose or not choose.
 * And also another key observation is the 2 subset sum is equal so basically is the total sum divide by 2. If the total
 * sum is odd means cannot be partitioned equally
 * So by using brute force, we will just simply use dfs and backtracking when the currSum is greater than half of the
 * sum. But the time complexity will be O(2^n)
 *
 * we can optimize it by using caching. But how do we implement it?
 * Just cache the result, so whenever we face the same problem can straight away use it
 * Time Complexity: O(n * sum(nums))
 * Space Complexity: O(n * sum(nums)) --> MLE
 *
 * How can we further optimize it by using dp and optimize the space complexity?
 * we can actually store all the possible sum that we can make while we traverse through the array
 * Then check see whether in the possible sum + the curent index can make it to half or not
 * And also another key observation is as long as we find the subset is equal to the target can straight away return
 * true because the other half will also be the same value no matter how
 * Time Complexity: O(n * sum(nums))
 * Space Complexity: O(sum(nums))
 * */
class Solution
{
  public:
    bool canPartition(std::vector<int> &nums)
    {
        auto sum{std::accumulate(nums.begin(), nums.end(), 0)};
        if (sum % 2)
            return false;
        int target{sum / 2};

        // top-down approach
        //
        // // caching
        // std::unordered_map<int, std::unordered_map<int, bool>> cache;
        //
        // std::function<bool(const int &, const int &)> dfs_backtracking = [&](const int &index, const int &currSum) {
        //     if (currSum == target)
        //         return true;
        //     if (index >= nums.size() || currSum > target)
        //         return false;
        //
        //     // caching
        //     if (cache.count(index) && cache[index].count(currSum))
        //         return cache[index][currSum];
        //     // choose
        //     bool choose{dfs_backtracking(index + 1, currSum + nums[index])};
        //     // not choose
        //     bool notChoose{dfs_backtracking(index + 1, currSum)};
        //
        //     return cache[index][currSum] = choose || notChoose;
        // };
        //
        // return dfs_backtracking(0, 0);

        // bottom-up approach
        std::unordered_set<int> dp;
        dp.insert(0);

        for (const auto &num : nums)
        {
            // cannot update the dp set while iterating through it might cause some logical error
            // so have a temp dp
            std::unordered_set<int> nextDp;
            for (const auto &avaiSum : dp)
            {
                if (avaiSum + num == target)
                    return true;
                nextDp.insert(avaiSum + num);
                nextDp.insert(avaiSum);
            }
            dp = nextDp;
        }
        return dp.count(target);
    }
};
