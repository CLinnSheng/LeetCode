#include <vector>

/*
 * Given a string.
 * Score of an array is defined as the product of its sum and its length
 *
 * Goal: Return the number of non-empty subarrays of nums whose score is strictly less than k.
 *
 * Intuition:
 * The naive way will just simply brute force it with a double loop but this will cost O(n^2)
 *
 * Can we further optimize it?
 * If we observe from the brute force way, we see that we are checking some overlapping subarray.
 * Subarray --> Sliding Window with a constraint
 * Hence, we can apply sliding window algo.
 * We will keep moving the right pointer if the subarray still obeying the requirements until the score is greater or
 * equal than k. Then we only move the left pointer, because is pointless to continue keep checking if already exceeds
 * because add more new element will only increase it but not decrease it. Then same for left pointer keep moving until
 * is less than k, and continue move right again.
 * but like this we only consider the subarray [i, j] how about the inner subarray also meet the requirement because it
 * contain less number so def be less than k. How do wecompute? simply just right - left + 1 Time Complexity: O(n)
 * */
using ll = long long;
class Solution
{
  public:
    ll countSubarrays(std::vector<int> &nums, ll k)
    {
        ll ans{};
        ll currSum{};

        int left{}, right{};
        while (right < nums.size())
        {
            currSum += nums[right];

            while (left <= right && (currSum * (right - left + 1)) >= k)
            {
                currSum -= nums[left];
                left++;
            }

            ans += (right - left + 1);
            right++;
        }
        return ans;
    }
};
