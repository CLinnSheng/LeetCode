#include <functional>
#include <vector>
#include <ios>
#include <iostream>

/*
Goal: Find all possible subsets from the nums
Intuition: Use dfs & backtracking method
*/
class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        std::vector<std::vector<int>> ans;
        std::vector<int> subset;
        
        std::function<void(int)> dfs = [&](int starting_index) {
        
            ans.emplace_back(subset);
            
            for (int i = starting_index; i < nums.size(); i++) {
                // Add new element into subset
                subset.emplace_back(nums[i]);
                // dfs
                dfs(i + 1);
                // backtracking by popping the latest insert element
                subset.pop_back();
            }
        };
        
        dfs(0);
        
        return ans;
    }
};