#include <bits/stdc++.h>
using namespace std;

/*
Goal: Find the two indices that add up to target
Intuition: Store the nums into a hash while iterating through the array and find the complement number at the same time
*/
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
        
            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            
            unordered_map<int, int> hashmap;
            
            for (int i = 0; i < nums.size(); i++) {
                if (hashmap.count(target - nums[i]))
                    return {i, hashmap[target - nums[i]]};
                else
                    hashmap[nums[i]] = i;
            }
            
            return {-1, -1};
        }
};