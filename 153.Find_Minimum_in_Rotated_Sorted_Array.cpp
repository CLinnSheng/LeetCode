#include <ios>
#include <vector>
#include <iostream>

/*
Given an rotated array with sorted elements.
So means that the number in the left & right of the smallest element is larger than it
eg: [4, 5, 6, 7, 0, 1, 2] it was ascending in a rotated array & 0 is the smallest

Goal: Find the lowest element in the array with the least time complexity

Intuition: We compare the middle element with the last element (Reason choose the last element because we can determine whether the lowest element is lies on the LHS or RHS of middle)
if middle > last
    lowest element is in the second half
    repeat on the right
else
    lowest element is in the left part
    repeat on the left
    
Time Complexity of Binary Search: O(logn)
*/

class Solution {
public:
    int findMin(std::vector<int>& nums) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int start = 0, end = nums.size() - 1;
        
        while (start < end) {
            
            int middle = start + (end - start) / 2;
            
            if (nums[middle] > nums[end]) start = middle + 1;
            else end = middle;
        } 
        
        return nums[start];
    }

};