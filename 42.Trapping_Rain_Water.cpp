#include <ios>
#include <iostream>
#include <vector>

/*
Goal: Compute how much water it can trap
Intuition: To compute the trapped water we need to know the height from each side adn then min(left, right) - height[i] --> water trap in that column
we can use 2 arrays to store every single position maxHeight from the left and the right
and then the amount of water trapped is just simply min(leftMax, rightMax) - height[i]
Instead of having 2 arrays we can use 2 pointers, 1 in the left and 1 in the right
both of them is responsible to compute the tracp water from each direction
Time Complexity: O(N)
*/

class Solution {
public:
    int trap(std::vector<int>& height) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        
        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int ttl_water = 0;
        
        while (left < right) {
            
            if (leftMax < rightMax) {
                // Keep updating the maximum height from the LHS & then compute every single index trapped water
                leftMax = std::max(leftMax, height[++left]);
                ttl_water += leftMax - height[left];
            }
            
            else {
                rightMax = std::max(rightMax, height[--right]);
                ttl_water += rightMax - height[right];
            }
            
        }
        
        return ttl_water;
    }
};