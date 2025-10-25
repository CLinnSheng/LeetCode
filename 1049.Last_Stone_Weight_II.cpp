#include <climits>
#include <cstdlib>
#include <numeric>
#include <vector>
/*
 * Each turn choose any 2 stone and smash them together
 * Result of smash got 2 possibilities
 * 1. x == y, both stones are destroyed
 * 2. x != y, push the new diff weight
 *
 * Goal: Return the smallest possible weight of the left stone otherwise 0 if no stone
 *
 * Intuition:
 * Need to find the way to choose 2stones such that the weight of the left stone is minimal
 * We think it in another way is actually like partitioning the stones into 2 groups such that the differnce
 * between their sum is minimized.
 * Eg: [1,3,2,4] --> [1,[3,2,4]] / [[1,3],[2,4]] / [[1,3,2],4]
 * so for every subset we need to repeat the same thing as well
 * So brute force basically just trying all possible subset
 * We trying to minimize sum(A) - sum(B) which is same as minimizing total - sum(B) - sum(B) --> total - 2 * sum(B)
 * Time Complexity: O(2^n)
 *
 * Observe from the recursive dfs, we can actually see doing some computation multiple times
 * We can improve it through caching/memoization
 * We pass 2 information every recursive, so the array will be 2d
 * Time Complexity: O(ttlSum/2 ^2)
 * */
class Solution
{
  private:
    int dfs(std::vector<int> &stones, int index, int currSum, int total, const int &targetSum,
            std::vector<std::vector<int>> &caching)
    {
        if (index == stones.size() || currSum >= targetSum)
        {
            return caching[index][currSum] = std::abs(total - 2 * currSum);
        }

        if (caching[index][currSum] != -1)
        {
            return caching[index][currSum];
        }

        // 2 Choice, whether include this stone or not
        return caching[index][currSum] =
                   std::min(dfs(stones, index + 1, currSum, total, targetSum, caching),
                            dfs(stones, index + 1, currSum + stones[index], total, targetSum, caching));
    }

  public:
    int lastStoneWeightII(std::vector<int> &stones)
    {
        int total = std::accumulate(stones.begin(), stones.end(), 0);
        std::vector<std::vector<int>> caching(stones.size(), std::vector<int>(total / 2 + 1, -1));
        // Caching[i][j] means the smallest weight at index i and the sum is j
        return dfs(stones, 0, 0, total, total / 2, caching);
    }
};
