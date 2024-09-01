#include <ios>
#include <vector>
#include <iostream>
/*
Goal: Check whether is target in the 2D matrix or not

Intuition: Given that each row in the 2d matrix is sorted in ascending order
The first integer of each row is greater than the last integer of the previous row.
First we must find out it belongs to each row then only saerch for the particular row
*/

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int n_row = matrix.size(), n_col = matrix[0].size();
        
        // Checking which row it belongs to
        int left = 0, right = n_row - 1;
        
        while (left < right) {
            
            int middle = left + (right - left) / 2;
            
            if (matrix[middle][0] > target) right = middle;
            else if (matrix[middle][0] < target) left = middle + 1;
            else return true;
        }
        
        std::cout << left;
        return true;
    }
};