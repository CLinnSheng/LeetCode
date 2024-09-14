#include <algorithm>
#include <climits>
#include <iostream>
#include <ios>
#include <vector>

/*
Consider a non-empty subarray from nums that has the maximum possible bitwise AND.let k be the maximum value of the bitwise AND of any subarray of nums. 
Then, only subarrays with a bitwise AND equal to k should be considered.
Goal: Return the length of the longest such subarray

Intuition: Need to find the maximum bitwise AND value of subarray
Notice that the bitwise AND of two different numbers will always be strictly less than the maximum of those two numbers.
So in another way we need to find the maximum value in the array
We can sort it first then find out the index of the largest value in the array, and then iterate from that index to check the length

Time Complexity: O(nlgn + n)
Space Complexity: O(1)

Another way is by using a variable to keep track of the maximum value, if met the some number we will count it
if meet another new max value, update again to 0
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution 
{
public:
    int longestSubarray(std::vector<int>& nums) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int max = INT_MIN, streak = 0, ans = 0;
        
        if (nums.size() == 0) return ans;
        
        for (const auto& num : nums)
        {
            if (num > max)
            {
                max = num;
                ans = streak = 0;
            }
            
            // checking its neighbor whether is it the same number
            if (max == num) streak++;
            // or else reset to 0
            else streak = 0;
            
            // Keep updating the length
            ans = std::max(ans, streak);
        }
        
        return ans;
    }
};