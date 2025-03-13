#include <algorithm>
#include <vector>
using std::vector;

/*
 * Given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali]
 * Each queries[i]:
 *  - Decrement the value at each index in the range [li, ri] in nums at most val
 *  - The amount by which each value is decremented can be chosen independently for each index.
 * Zero array: An array with all elements equal to 0
 *
 * Goal: Return the minimum possible non-negative value of k or else -1
 *
 * Intuition:
 * Brute force way is just iterate through queries, and then apply the decrement to the element
 * independently. Then check through the array whether is it all equal to 0 or not.
 * So if it already equal to 0, we can also apply the decrement because smaller than 0 is also same as equal to 0.
 * But this is super inefficient because iterate through the queries will take O(m) and then
 * applying the decrement at worst is also O(n) and then checking it will be O(n)
 *
 * Which part can we optimize? Is actually only the part of doing the decremental.
 * So instead of going changing every index, what we can do is actually just set at the boundary.
 * For eg: [2, 0, 2] & queries = [[0,2,1],[0,2,1],[1,1,3]]
 * Have an array to track the decrement at every index. [0, 0, 0, 0]
 * (n + 1) because the boundary of li and ri is inclusive
 * queries[i] -> [1, 0, 0, -1] so how can we check? just iterate through the new array.
 * At decrement[0] = 1 means that from this index in nums will have to decrement by 1.
 * So as long as currentDifferences at ith index is >= nums[i] then it must be 0
 * THe reason why differences[3] is -1 because the decremnt of 1 is only applies from [0,2] so need to add back
 * So now how do we know what is the minimum k? we can do binary search from 0 to n
 *
 * Actually we can even further optimize to linear time.
 * We can utilize the decrement array we had just now. So in the previous approach, we iterate through the queries
 * twice. One in binary search and one for checking whether can be 0 or not Why not we just iterate it once, so what we
 * can do is also use the decrement conecpt previously. And when we iterate through the nums, we will straight away
 * check how many queries do we need to do get the current index smaller or equal to 0
 * Time Complexity: O(m + n)
 * */
class Solution
{
  private:
    // O(n + m)
    bool helper(const vector<int> &nums, const vector<vector<int>> &queries, int k)
    {
        int n(nums.size());
        vector<int> decrement(n + 1, 0);

        for (int i{}; i < k; i++)
        {
            // at queries[i][0] index we need to decrement
            decrement[queries[i][0]] += queries[i][2];

            // at queries[i][2] + 1, from this current index dont have to decrement anymore so add back
            decrement[queries[i][1] + 1] -= queries[i][2];
        }

        int currDecrement{};

        // checking whether is it equal to 0 or not
        for (int i{}; i < n; i++)
        {
            // apply the decrement
            currDecrement += decrement[i];

            if (currDecrement < nums[i])
                return false;
        }
        return true;
    }

  public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        // Approach 1: O(nlg(n+m))
        // int n(queries.size());
        // int left{}, right(queries.size());
        //
        // // base case check whether n query can make all to 0 or not
        // if (!helper(nums, queries, right))
        //     return -1;
        //
        // int k{};
        //
        // // O(nlgA)
        // while (left <= right)
        // {
        //     int middle(left + (right - left) / 2);
        //
        //     // O(A)
        //     if (helper(nums, queries, middle))
        //     {
        //         right = middle - 1;
        //         k = middle;
        //     }
        //     else
        //         left = middle + 1;
        // }
        //
        // // O(nlg(n + m))
        // return left;

        // Approach 2: O(n + m)

        int n(nums.size());
        vector<int> decrement(n + 1, 0);
        int currDecrement{};
        int k{};
        // update the decrement while iterating through nums
        for (int i{}; i < nums.size(); i++)
        {
            // check whether the currDecrement until k query can make the current elemnt smaller or equal to 0 or not
            while (currDecrement + decrement[i] < nums[i])
            {
                // keep iterating through the queries
                // until it can get it to 0
                k++;

                if (k > queries.size())
                    return -1;

                int left{queries[k - 1][0]}, right{queries[k - 1][1]}, val{queries[k - 1][2]};

                // now for updating decrement
                // we dont actually have update the decrement for every single query
                // has to depend on the index.
                // if the index > right, then this query is useless for us
                if (right >= i)
                {
                    // left boundary, we only take the max(left, i)
                    // because if left is smaller than i, we only need to update at i because we already process
                    // everything before i
                    decrement[std::max(i, left)] += val;
                    // for right boundary, we need it in the future
                    decrement[right] -= val;
                }
            }
            currDecrement += decrement[i];
        }
        return k;
    }
};
