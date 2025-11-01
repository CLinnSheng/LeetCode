#include <numeric>
#include <vector>
/*
 * Even number of piles. piles[i] --> number of stones
 * Total no of stones are odd number
 * They take turn but alice will starting first
 * But every time a player can only take the it from the first or last pile
 *
 * Goal: End the game with no stone left. And check whether alice in or not
 * The person takes the most stone win
 *
 * Intuition:
 * Okay so both player will play optimally. At every single move they will take the pile with the most stone. But taking
 * the piles iwth most stone doenst necessary guarantee a win.
 * So we need to try out all possible path. So at every single step, we can either pick first or last.
 * Just use recursive
 * So instead of keep tracking of both scores, instead we can just compute all possible path by Alice only. Because
 * alice is the first one to start and the bob stone will just simply be total - aliceSum
 * So we need to compute the maximumSum that alice can take
 * Time Complexity: O(2^n)
 *
 * Observation from brute force, we doing repetitive computation
 * We can optimize it by using caching
 * Time Complexity: O(n^2)
 *
 * */
class Solution
{
  private:
    int dfs(std::vector<int> &piles, int left, int right, std::vector<std::vector<int>> &cache)
    {
        if (left > right)
        {
            return 0;
        }

        if (cache[left][right] != -1)
        {
            return cache[left][right];
        }

        // Need to determine whose turn is it
        // Alice turn is always when the piles have even size
        bool alice = (right - left) % 2;
        int leftBucket = alice ? piles[left] : 0;
        int rightBucket = alice ? piles[right] : 0;
        return cache[left][right] = std::max(dfs(piles, left + 1, right, cache) + leftBucket,
                                             dfs(piles, left, right - 1, cache) + rightBucket);
    };

  public:
    bool stoneGame(std::vector<int> &piles)
    {
        std::vector<std::vector<int>> cache(piles.size(), std::vector<int>(piles.size(), -1));
        int totalStone{std::accumulate(piles.begin(), piles.end(), 0)};
        int aliceSum = dfs(piles, 0, piles.size() - 1, cache);

        return aliceSum > totalStone - aliceSum;
    }
};
