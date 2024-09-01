#include <ios>
#include <iostream>
#include <vector>

/*
Given an array, m stands for number of row and n stands for number of col
Goal: Return a 2d array from 1d array with m row and n col if possible else reutrn an empty 2d array
Intuition: 2d array can only be transformed if & only if m * n == length of original
*/

class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        std::vector<std::vector<int>> ans;
        int cnt = 0, size = original.size();

        if (m * n != size) return ans;

        for (int i = 0; i < m; i++){            
            std::vector<int> sub;
            if (cnt >= size)    break;
            for (int j = 0; j < n; j++)
                if (cnt < size) sub.emplace_back(original[cnt++]);
                else break;
                
            ans.emplace_back(sub);
        }                
        
        return ans;
    }
};