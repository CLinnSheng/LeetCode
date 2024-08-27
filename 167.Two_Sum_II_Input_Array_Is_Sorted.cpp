#include <ios>
#include <iostream>
#include <vector>

/*
Goal: Return the index of 2 elements that sum up to target
Constraint: Cannot use the same element twice
Intuition: Since the array is sorted, we can use 2 pointer (1 in the front & 1 in the back)
Time Complexity is O(n) since we just iterate the array once
*/
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int start = 0, end = numbers.size() - 1;
        
        // since cannot use the same element, so we break once start < end
        while (start < end) {
            
            int sum = numbers[start] + numbers[end];
            
            if (sum > target) end--;
            else if (sum < target) start++;
            else return {start + 1, end + 1};
            
        }
        
        return { };
    }
};