#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
Intuition: Try to compute the sum, then sort it and then sum it from index left to right
Use priority queue to achieve greater time complexity so that we dont have the compute the sum
for all sub array just from 1 to right is enough
*/
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // we just straight away push it all without computing sum
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        int ans = 0, mod = 1e9 + 7;

        for (int i = 0; i < right; i++){

            auto [curr_sum, index] = pq.top();
            pq.pop();

            // the range that we want
            if (i >= left - 1)
                ans = (ans + curr_sum) % mod;
            
            // to check to make sure not out of bound
            if (index + 1 < n){        
                curr_sum += nums[++index];
                pq.push({curr_sum, index});
            }

        }

        return ans;
    }
};