#include <functional>
#include <vector>

/*
 * Goal: Return the sum of all XOR totals for every subset of nums.
 * Note: Subset with the same elements should be counted multiple times.
 *
 * Intuition:
 * Lets say we have A XOR B, if we want to get the orignal value of A we just need to A XOR B XOR B again.
 * Find all the possible subset, this is actually a tree decision problem.
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    int subsetXORSum(std::vector<int> &nums)
    {
        std::function<int(const int &, const int &)> dfs = [&](const int &index, const int &currTtl) {
            if (index == nums.size())
                return currTtl;
            return dfs(index + 1, currTtl ^ nums[index]) + dfs(index + 1, currTtl);
        };
        return dfs(0, 0);
    }
};
