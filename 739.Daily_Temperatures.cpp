#include <bits/stdc++.h>
using namespace std;

/*
Intuition: Need to find the number of days to reach temperature than its current day temperature
have a stack to store the indices of those days havent the answer yet
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> ans(temperatures.size(), 0);
        deque<int> stack;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.back()]) {
                ans[stack.back()] = i - stack.back();
                stack.pop_back();
            }

            stack.emplace_back(i);
        }

        return ans;
    }
};