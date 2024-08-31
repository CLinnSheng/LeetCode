#include <ios>
#include <vector>
#include <iostream>

/*
Given that the array is sorted in ascending order
Intuition: We can straight apply binary search
Time Complexity: O(lgn)
*/

/*
Some detailed explanation about the while loop condition:
1. (start < end)
    a. Searching for an exact match / index
    b. Find the first occurence of a condition
    c. Terminate when start and end converge to a single element
    
2. (start <= end)
    a. Seraching for a range or a minimum/maximum value
    b. Include the end value in search range
*/
class Solution {
public:
    int search(std::vector<int>& nums, int target)
    {    
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int start = 0, end = nums.size() - 1;
        
        while (start < end) {
            
            int middle = start + (end - start) / 2;
            
            if (nums[middle] > target) end = middle;
            else if (nums[middle] < target) start = middle + 1;
            return middle;
        }
        return -1;
    }
};