#include <algorithm>
#include <unordered_map>
#include <vector>
using std::vector;

/*
 * Goal: return the length of the longest Fibonacci like subsequence of arr
 * eg: subsequence a,b,c where c => a + b & a,b,c is a subarray from arr where it can remove some element in the middle
 *
 * Intuition:
 * For fibonanci sequence, if it only contains 2 element, then it definitely inside the fibonanci sequence.
 * We can actually use dp to cache where dp[i][j] means that for sequences that end with arr[i] & arr[j] maximum length.
 * So when we trying all the possible indexes, we will update the dp table if arr[i] + arr[j] exists inside the array.
 * Then we will update dp[j][index] = dp[i][j] + 1
 *
 * Time Complexity: O(n^2)
 * */
class Solution
{
  public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n(arr.size());
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen{};

        // a hash table to store the value -> index
        std::unordered_map<int, int> map;

        // populate the dp table with 2 first
        for (int i{}; i < n; i++)
        {
            map[arr[i]] = i;
            for (int j{i + 1}; j < n; j++)
                dp[i][j] = 2;
        }

        // check through every single pair indices i & j where i < j
        for (int i{}; i < n; i++)
        {
            for (int j{i + 1}; j < n; j++)
            {
                // compute the next value with the last 2 element
                int nxtVal{arr[i] + arr[j]};

                // then determine whether got this value in the array or not
                if (map.count(nxtVal))
                {
                    int index{map[nxtVal]};
                    // then we update it, since because we have nxtVal in the arr so we just update
                    // the sequences that end with j & index
                    dp[j][index] = dp[i][j] + 1;
                }
            }
        }

        for (int i{}; i < n; i++)
            for (int j{i + 1}; j < n; j++)
                maxLen = std::max(maxLen, dp[i][j]);

        return maxLen == 2 ? 0 : maxLen;
    }
};
