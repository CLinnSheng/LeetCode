#include <bits/stdc++.h>
using namespace std;
/*
Goal: Find the list of maximum elements in each window of size
Intuition: The number of window of size k available in array size of n => n - k + 1
Since we need to keep track of the maximum element in the window everytime the window moves
we can use deque data structure as it is more flexible to be remove or add at the front and back
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size();
        if (!n) return {};

        vector<int> ans(n - k + 1);

        // Store the index of the biggest element in the current window
        deque<int> window;

        // Pointer for the window
        int l = 0, r =0;

        while (r < n){

            while (!window.empty() && nums[r] > nums[window.back()])
                window.pop_back();

            // Maximum element of the current window size is always at the front
            window.emplace_back(r);

            // We check to see whether do we move the window to the right (left pointer)
            if (l > window.front())
                window.pop_front();

            // check again for the right pointer whether do we achieve the required window size
            if (r + 1 >= k){
                ans[l] = nums[window.front()];
                // since we achive the required window size, so we move the window
                l++;
            }

            r++;
        }
        
        return ans;
    }
};