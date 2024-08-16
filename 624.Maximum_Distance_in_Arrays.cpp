#include <bits/stdc++.h>
using namespace std;
/*
Given an m arrays and is sorted in ascending order
Need to pick 2 integers from 2 different arrays and calculate the distance (abs diff)
return the maximum distance

Intuition: Only care about the min and max from every single array
array[0] min and array[size - 1] max
brute force will be O(n^2) by just comparing every single array come after it

use greedy solution by keep updating the min, max, and maximum distance for every array we iterate
We need to avoid compute distance from the same array
*/
class Solution{
    public:
        int maxDistance(vector<vector<int>>& arrays) {
            
            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            
            int cur_min = arrays[0].front(), cur_max = arrays[0].back();
            int ans = INT_MIN;
            
            for (int i = 1; i < arrays.size(); i++) {
                // this will prevent compute from the same array by starting from the second array
                ans = max(ans, max(arrays[i].back() - cur_min, cur_max - arrays[i].front()));
                
                cur_min = min(cur_min, arrays[i].front());
                cur_max = max(cur_max, arrays[i].back());
            }
            
            return ans;
        }
};