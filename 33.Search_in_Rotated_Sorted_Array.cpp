#include <vector>
#include <iostream>

/*
Goal: Search the target element in a rotated sorted array
Intuition: Use binary search to find it
Algo:
i. Check whether is it in the left part (by comparing is it in the range of [nums[left], nums[middle]]) or the right part
*/
class Solution {
public:
    int search(std::vector<int>& nums, int target) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int left = 0, right = nums.size() - 1;

        while (left <= right) {

            int middle = left + (right - left) / 2;
            
            if (nums[middle] == target) return middle;
            else if (nums[middle] >= nums[left]) {
                if (nums[middle] >= target && nums[left] <= target) right = middle - 1;
                else left = middle + 1;
            }
            else {
                if (nums[middle] <= target && nums[right] >= target) left = middle + 1;
                else right = middle - 1;
            }
            

        }
        return -1;
    }
};