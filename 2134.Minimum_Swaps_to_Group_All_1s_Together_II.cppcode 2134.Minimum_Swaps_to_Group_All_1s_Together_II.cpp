#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
Intuitoin: Is look like a circular loop, we can append the orignal array
to the end to become 2 * array
We can use sliding window technique to find the a window size of number of 1's in the
array that contain the most 1's
Then the number of 1 will just be the number of 0 in the window
*/
    int minSwaps(vector<int>& nums) {

        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int cnt_1 = 0, n = nums.size();

        for (const auto &num : nums)
            if (num)
                cnt_1++;

        int window_one = 0, window_one_max = INT_MIN;
        int l = 0, r = 0;

        for (; r < 2 * n; r++){
            if (nums[r % n])
                window_one++;

            // if exceed the maximum window size which is the total number of 1s in the array
            if (r - l + 1 > cnt_1)
                // shift the window to the right
                window_one -= nums[l++ % n];
    
            window_one_max = max(window_one_max, window_one);
            
        }

        // number of swap = size of maximum window - total number of 1s in the window
        return cnt_1 - window_one_max;        
    }
};