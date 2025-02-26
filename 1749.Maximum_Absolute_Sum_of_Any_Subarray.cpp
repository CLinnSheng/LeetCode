#include <algorithm>
#include <cstdlib>
#include <vector>
using std::vector;

/*
 * The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).
 * Goal: Return the maximum absolute sum of any subarray of nums.
 * NOTE: Empty subarray is allow
 *
 * Intuition:
 * Since we want to find the maximum absolute sum right, then maximum value & minimum value would be the maximum
 * absolute value
 * We can solve it naively through the double loop by trying all possible subarray.
 * But this will be having time complexity of O(n^2)
 * By using naive approach, I observe that there are repetition of doing the same stuff.
 * So we can optimize it to O(n) but how?
 * Can we utilize the information we have computed before.
 *
 * Method1:
 * What we can do is keep track of the minPrefixSum & maxPrefixSum before index i
 * So when iterate through, we will keep track of the currentSum from 0 to index i.
 * So we need to compare the array 0 to i and also the subarray a where a is 0 < a < i.
 * So how do we correctly choose the right subarray?
 * There are 2 possible subarays which will have the maxPrefixSum & minPrefixSum.
 * So for currentSum <= 0, we need to remove the subarray part which have the maximumPrefixSum, so this will in result
 * with greater negative sum for the subarray. In the other hand for currentSum >, 0, we try to remove subarray part
 * which have the minPrefixSum, so this will in result with greater positive sum for the subarray. Time Complexity: O(n)
 * */
class Solution
{
  public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int minPrefixSum{}, maxPrefixSum{}, currSum{};
        int maxSum{};

        for (const auto &num : nums)
        {
            currSum += num;

            minPrefixSum = std::min(minPrefixSum, currSum);
            maxPrefixSum = std::max(maxPrefixSum, currSum);

            // remove the minPrefixSum so that we can get greater sum
            if (currSum >= 0)
            {
                maxSum = std::max(maxSum, std::max(std::abs(currSum - minPrefixSum), currSum));
            }
            else
            {

                maxSum = std::max(maxSum, std::max(std::abs(currSum - maxPrefixSum), currSum));
            }
        }
        return maxSum;
    }
};
