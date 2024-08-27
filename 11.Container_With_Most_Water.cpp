#include <algorithm>
#include <climits>
#include <ios>
#include <iostream>
#include <vector>

/*
Given an array of height
Goal: Return the container with most water which is the maximum area
Instuition: Can use 2 pointer and try to find the maximum area by moving the pointer with shorter height
Time Complexity: O(n)
*/
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int size = height.size();
        
        int start = 0, end = size - 1;
        
        int max_area = INT_MIN;
        
        while (start < end) {
            
            max_area = std::max(max_area, std::min(height[start], height[end]) * (end - start));
            
            if (height[start] > height[end]) end--;
            else start++;
        
        }
        
        return max_area;
    }
};