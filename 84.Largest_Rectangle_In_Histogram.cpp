#include <climits>
#include <deque>
#include <ios>
#include <iostream>
#include <vector>

/*
Goal: Return the largest rectangle in histogram from an array of heights
Intuition:
We want to know for each bar hw far can it extend to the right 
keep checking from n - 1 bar to see whether it can extend to n bar or not & repeat it until the first bar
This lead to us to use stack data structure to implement this algo

Algo:
1. Have a stack that holds the index & height
2. Push the first element into the stack
3. Repeatly push all the elements into the stack
    i. if the newly element push is smaller than its previous element, compute the area for its previous elemetnt until reach an element smaller than the new element
        a. Extend as much as possible when computing area because the height is increasing
    ii. Push the new element with the index from the last pop element because we also can form a rectangle by extending to left
Time Complexity: O(n)

In simple term: we try to extend each bar as long as possible    
*/
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) 
    {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int n_bar = heights.size();
        
        if (n_bar == 0) return 0;
        
        int max_area = INT_MIN;
        // Store the index & height
        std::deque<std::pair<int, int>> stack;
    
        for (int i = 0; i < n_bar; i++) {
       
            int height = heights[i];
            int starting_index = i;
            
            while (!stack.empty() && stack.back().second > height) {
                
                auto pair_element = stack.back();
                starting_index = pair_element.first; 
                int index_height = pair_element.second;
                stack.pop_back();
                
                // Try to extend the previous element to the right until reaching the lower boundary of current bar
                max_area = std::max(max_area, (i - starting_index) * index_height);
            }
            
            // Push into the stack with the index with the current bar try to extend to the left as much as possible
            stack.emplace_back(starting_index, height);
        }
        
        // After pushing all elements into the stack, compute the area of the elements left in the stack
        while (!stack.empty()) {
            
            auto [index, height] = stack.back();
            stack.pop_back();
            
            max_area = std::max(max_area, (n_bar - index) * height);

        }
        
        return max_area;
    }
};