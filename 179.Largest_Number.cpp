#include <ios>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

/*
Given an array of number
Goal: Arrange the numbers such that it form the largest number

Intuition: We need to compare how the 2 string cat and equal to wat
eg: 30 & 3 : 330 > 303
Time Complexity: O(nlgn)
Space Complexity: O(n)
*/

struct Comparator 
{
    bool operator()(const int n1, const int n2)
    { 
        auto temp1 = std::to_string(n1);
        auto temp2 = std::to_string(n2);
        
        return temp1 + temp2 < temp2 + temp1;
    }
};

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        std::priority_queue<int, std::vector<int>, Comparator> maxHeap(nums.begin(), nums.end());
        
        std::string ans = "";
        
        while (!maxHeap.empty())
        {
            auto temp = maxHeap.top();
            maxHeap.pop();
            
            ans += std::to_string(temp);
        }
        
        // Handling cases when there the array of numbers contain just 0 & more than 1 zeros
        return ans[0] == '0'? "0" : ans;
    }
};