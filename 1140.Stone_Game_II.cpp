#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <vector>
using namespace std;

/*
 * Each player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.
 * Then set M = max(M, X). Initially, M = 1
 * Goal: maximum stones get by Alice
 * NOTE: Each player play optimally.
 *
 * Intuition:
 * This is a decision tree problem where at every index each player can either take 1 <= X <= 2M stones, and the move it
 * makes is optimal. So the parameter we need to pass is the turn, index and also the current M value. The dfs method
 * will be returning the most stones taken by Alice. SO basically when bob turn we simply need to minimize the most
 * stones taken by Alice.
 * We can optimize it using cache
 * So it will be a 3d matrix
 *
 * Time Complexity: O(n * n * n) --> Iterate N index and N possible for M and then the inner for loop
 */
class Solution
{
  public:
    int stoneGameII(vector<int> &piles)
    {
        std::vector<std::vector<std::vector<int>>> cache(
            2, std::vector<std::vector<int>>(piles.size() + 1, std::vector<int>(piles.size() + 1, -1)));

        std::function<int(bool, int, int)> dfs = [&](bool alice, int index, int M) {
            // Check boundary
            if (index >= piles.size())
            {
                return 0;
            }

            if (cache[alice][index][M] != -1)
            {
                return cache[alice][index][M];
            }

            int res = alice ? 0 : INT_MAX; // Handle Alice and Bob turn
            int ttl{};                     // Prefix Sum
            for (int i{1}; i <= 2 * M; i++)
            {
                // Boundary Checking
                if (index + i > piles.size())
                {
                    break;
                }

                ttl += piles[index + i - 1];

                if (alice)
                {
                    res = std::max(res, ttl + dfs(!alice, index + i, std::max(i, M)));
                }
                else
                {
                    res = std::min(res, dfs(!alice, index + i, std::max(i, M)));
                }
            }

            return cache[alice][index][M] = res;
        };

        return dfs(true, 0, 1);
    }
};
