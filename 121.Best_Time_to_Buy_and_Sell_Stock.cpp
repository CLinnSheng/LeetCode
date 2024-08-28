#include <ios>
#include <iostream>
#include <vector>

/*
Goal: Return the maxium profit
Given an array of prices for n day where prices[i] is the price of the given stock on the ith day
Intuition: Selling price must be higher than the buying price, can use a sliding window algo
keep expanding the window if selling price is higher than buying price & only shift the buying days when we occur selling < buying that means we can buy at that day because it has lwoer price
*/
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int left = 0, right = left + 1;
        int maxProfit = 0;
        int days = prices.size();
        
        while (right < days) {
            
            if (prices[left] < prices[right])
                maxProfit = std::max(maxProfit, prices[right] - prices[left]);
            else
                left = right;
                
            right++;
        }
        
        return maxProfit;
    }
};