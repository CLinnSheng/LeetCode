#include <algorithm>
#include <vector>

/*
 * Goal: Return the number of subarrays where the maximum element of nums appear at least k times in that subarray.
 *
 * Intuition:
 * The thing we need is the max element, so first we need to get the max element in the array.
 * After that, the brute force way will just simply loop through the array twice and try every single possible subarray
 * and check whether is it appear at least k times. Time Complexity: O(n^2)
 *
 * How can we optiimze it? If we observe from the brute force, we can observe we are checking overlapping subarray.
 * Another important is "SUBARRAY" --> sliding window.
 * We can use sliding window algo, to find the window that has maximum appear exactly k times. Then we just simply take
 * the length minus the right pointer, because any new element whether is it the max element or not is also consider a
 * good subarray. Time Complexity: O(n)
 * */
class Solution
{
    using ll = long long;

  public:
    ll countSubarrays(std::vector<int> &nums, int k)
    {
        ll ans{};

        int maxElement{};
        for (const auto &num : nums)
            maxElement = std::max(maxElement, num);

        int left{}, right{}, cntMax{};
        while (right < nums.size())
        {
            if (nums[right] == maxElement)
                cntMax++;

            // need to consider the situation where the array size is only 1
            while (left <= right && cntMax >= k)
            {
                ans += nums.size() - right;
                cntMax += nums[left] == maxElement ? -1 : 0;
                left++;
            }

            right++;
        }

        return ans;
    }
};
