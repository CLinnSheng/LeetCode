#include <unordered_map>
#include <vector>
using std::vector;

/*
 * Goal: Return the total number of subarrays whose sum equals to k.
 * Subarray: Contiguous non-empty sequence of elements within an array.
 *
 * Intuition:
 * Brute force way will be double looping to try all possible subarray
 * But from the brute force approach, we can see that we keep computing the some overlapping subarray.
 * Is there any efficient to do it?
 *
 * Use we can use sliding window.
 * So what we can do is keep moving the right pointer until the subarray is equal to K.
 * Then move the left pointer and repeat again
 *
 * Howeve there's one constraint which is the value might be negative, therefor we cannot implement sliding window.
 * Because how can we make sure if keep moving the right pointer it still can achieve the sum K, because is not always
 * guaranteed to increase.
 *
 * There's another clever way is actually using prefix sum. prefixSum[i] will have the number of possible subarray to
 * form i Then to find how mnay subarray until ith index, simply need to find how many possible subarray of k - currSum
 * this is because the prefixSum[diff] will give us how many subarray can be form of sum value equal to diff.
 * Then this tell us how many way we can remove the subarray of sum diff.
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans{};
        std::unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;

        int currSum{};

        for (const auto &num : nums)
        {
            currSum += num;
            ans += prefixSum[currSum - k];
            prefixSum[currSum]++;
        }
        return ans;
    }
};
