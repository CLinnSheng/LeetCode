#include <vector>

/*
 * queries[i] = [li,ri]
 * Each query:
 * i. Select a subset of indices within the range [li, ri] in nums
 * ii.  Decrement the values aat the selected indices by 1.
 * Zero Array: Where all elements are equal to 0.
 *
 * Goal: Check whether is it possible to transform nums into a Zero Array after processing all the queries sequentially,
 * otherwise return false
 *
 * IMPORTANT: 0 <= nums[i] <= 10^5
 * Intuition:
 * Each query we can choose to decrement any of the indices within the range [li, ri].
 * So, we only choose to decrement those greater than 0.
 * The brute force will be looping every queries which will take O(n^2)
 *
 * How can we optimize it? How can we make it within 1 loop?
 * How can we check it without really looping through the range?
 * Prefix Sum --> Store the operations can be done at each indices
 * Since is accumulative from previous index we need to use some kind of interval style of array to keep track of the
 * decrement Which i have an array where arr[i] is the number of decrement i can make in this indices. So we can just
 * simply check by arr[i] >= nums[i] if it is smaller means is impossible to make it to 0 Time Complexity: O(n)
 * */
class Solution
{
  public:
    bool isZeroArray(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
    {
        int n(nums.size());
        std::vector<int> decrement_interval(n + 1);

        for (const auto &query : queries)
        {
            decrement_interval[query[0]]++;
            decrement_interval[query[1] + 1]--;
        }

        std::vector<int> decrement(n, 0);
        int currDecrement{};
        for (int i{}; i < n; i++)
        {
            currDecrement += decrement_interval[i];
            if (currDecrement < nums[i])
                return false;
        }
        return true;
    }
};
