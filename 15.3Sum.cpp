#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

/*
Goal: Return all duplicates that sum up to 0
Constraint: The set must not contain duplicate triplets
Intuition: Fix one elements that we can use the same approach as 2sum
Besides that, we can also sort the array so for the fix element that is more than 0 we can omit it
Time Complexity: O(n2) because of the double loop
*/

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            
            if (nums[i] > 0) break;
            if ( i > 0 && nums[i] == nums[i - 1]) continue;
            
            int start = i + 1, end = size - 1;
            
            while (start < end) {
                
                int temp_sum = nums[i] + nums[start] + nums[end];
                
                if (temp_sum > 0) end--;
                else if (temp_sum < 0) start++;
                else {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    
                    start++; end--;
                    
                    while (start < end && nums[start] == nums[start - 1])
                        start++;
                }
                
            }
        }
        return ans;
    }
};