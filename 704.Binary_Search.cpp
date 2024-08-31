#include <ios>
#include <vector>
#include <iostream>

/*
Given that the array is sorted in ascending order
Intuition: We can straight apply binary search
Time Complexity: O(n)
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