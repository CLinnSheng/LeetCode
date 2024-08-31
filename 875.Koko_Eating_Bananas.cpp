#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <vector>
#include <cmath>

/*
Given n piles of banana, the ith pile has piles[i] bananas. Guard have gone and will come back in h hours
Goal : Return the minimum integer k such that she can eat all the bananas within h hours.

Intuition: Possible eating rate of banana is (1, maximum number of banana in all those piles);
Use a binary search in that range such that k is less than or equal to h
K IS MINIMUM!!
Time Complexity: O(nlgm) m is the maximum number of banana in the pile
*/

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        // Sort the piles, so that we can get the largest number of banna exist in a pile
        // O(nlgn)
        std::sort(piles.begin(), piles.end());
        
        // Range of k (Rate of number of banans ate per hour)
        int start = 1, end = piles.back();
        
        // Use binary search
        while (start <= end) {
            
            int middle = start + (end - start) / 2;
            long long time_taken = 0;
            
            // Compute the number of hours required to eat all the pile based on middle
            for (const auto& banana : piles)
                time_taken += ceil(static_cast<double>(banana) / middle);
            
            // it takes more time than the minimum hours, so we need to increase the rate
            if (time_taken > h) start = middle + 1;
            // takes less time than the minimum hours, we will try to continue to find the minimum rate
            else end = middle - 1;
                
        }
        
        return start;
    }
};