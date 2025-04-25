#include <unordered_map>
#include <vector>

/*
 * Find the count of subarrays that are interesting.
 * nums[l..r] is interesting if:
 * i. cnt be the number of indices i in the range [l, r] such that nums[i] % modulo == k. Then, cnt % modulo == k
 *
 * Goal: Return an integer denoting the count of interesting subarrays.
 *
 * Intuition:
 * Key observation is nums[i] % modulo == k can actually precompute rather than cnt % modulo == k
 * because we dont have the information of cnt in a certain range
 * therefor we can create a prefix sum from there where counts[i] tell us how many number of indices where nums[i] %
 * modulo == k from 0 to i
 *
 * The brute force way will be trying all possible subarray which will take O(n^2)
 * There is actually overlapping subarray.
 * How can we reduce to O(n) with the help of the prefix?
 *
 * */
class Solution
{
  public:
    long long countInterestingSubarrays(std::vector<int> &nums, int modulo, int k)
    {
        int n = nums.size();
        std::unordered_map<int, int> cnt;
        long long res = 0;
        int prefix = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++)
        {
            prefix += nums[i] % modulo == k;
            res += cnt[(prefix - k + modulo) % modulo];
            cnt[prefix % modulo]++;
        }
        return res;
    }
};
