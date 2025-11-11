#include <climits>
#include <numeric>
#include <string>
#include <vector>
/*
 * Alice Start First. Each turn, player can take 1,2 or 3 from the first remaining stones in a row
 * Score start from 0
 * Alice and Bob play optimally.
 *
 * Goal: Who will win the game?
 *
 * Intuition:
 * So at each step we can either take 1 stone, 2 stone or 3 stone.
 * And each player will be playing optimally. So we can brute force choose 1 of the 3 decision
 * that will maximize the difference in score between Alice and Bob best move
 * Time Complexity: O(3^n)
 *
 * We can use cache to optimize it because we can see repetitive computation
 * And we only passing 1 parameter to the recursive function therefor will be 1d array
 * so dp[i] --> max diff at from index i
 * Time Complexity: O(n)
 * */
class Solution
{
  private:
    int dfs(std::vector<int> &stoneValue, int stoneIndex, std::vector<int> &cache)
    {
        // Base Case
        if (stoneIndex >= stoneValue.size())
        {
            return 0;
        }

        if (cache[stoneIndex] != INT_MIN)
        {
            return cache[stoneIndex];
        }

        int stoneSum{}, maxDiff{INT_MIN};
        for (int k{}; stoneIndex + k < stoneValue.size() && k < 3; ++k)
        {
            stoneSum += stoneValue[stoneIndex + k];
            maxDiff = std::max(maxDiff, stoneSum - dfs(stoneValue, stoneIndex + k + 1, cache));
        }
        return cache[stoneIndex] = maxDiff;
    }

  public:
    std::string stoneGameIII(std::vector<int> &stoneValue)
    {
        std::vector<int> cache(stoneValue.size(), INT_MIN);
        int diff = dfs(stoneValue, 0, cache);
        return diff == 0 ? "Tie" : diff > 0 ? "Alice" : "Bob";
    }
};
