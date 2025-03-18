#include <algorithm>
#include <vector>

/*
 * Given an array. Subarray of nums is nice if the bitwise AND of every pair of elements
 * that aren in differenet positions in the subarray is equal to 0.
 * Goal: Return the length of the longest nice subarray.
 * Subarray: Contiguous part of an array
 * NOTE: Subarrays of length 1 are always considered nice.
 *
 * Intuition:
 * Contiguous Subarray --> DP / Siding window
 * Nice meaning that if we AND it to result will be 0
 * So means that the every bit will have different value
 *
 * In brute force, we will just check every single possible subarray
 * This will result in O(n^2)
 *
 * Actually from the observation of brute force, we can see theres repeating work
 * We can just use sliding window to prevent any repeated work. So if the current subarray is nice we will just keep
 * moving right pointer. Until not nice and then move left pointer until it is nice. So how do we check within the
 * window where every pair of elements AND equal to 0. Okay, what we really care is just about the bit instead of the
 * vlaue. for eg: 3 -> 0011, 8 --> 1000, 48 -> 110000 if this subarray is nice means that (3,8) & (3,48) & (8,48) all
 * this 3 pairs of AND result in 0 We care only about the position bit value, so we can just OR it like dry run: 3 & 8
 * --> 0 then we OR it 3 | 8 --> 1011 then 1011 & 110000 --> 0 Time Complexity: O(n)
 * */
class Solution
{
  public:
    int longestNiceSubarray(std::vector<int> &nums)
    {
        int answer{}, curr{};
        int left{}, right{};

        while (right < nums.size())
        {
            // check whether do we need to move the left pointer
            // in another whether the new subarray is nice or not
            while (curr & nums[right])
            {
                // moving the left pointer
                // removing the left pointer value from current
                curr ^= nums[left];
                left++;
            }

            answer = std::max(answer, right - left + 1);
            curr |= nums[right];
        }

        return answer;
    }
};
