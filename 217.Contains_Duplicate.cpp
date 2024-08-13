#include <bits/stdc++.h>
using namespace std;

/*
store all the element in the hashmap and then iterate through the array again to find out the duplicates
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, int> freq;

        for (const auto &num : nums)
            freq[num]++;

        for (const auto &num : nums) {
            freq[num]--;
            if (freq[num] > 0)
                return true;
        }

        return false;
    }
};