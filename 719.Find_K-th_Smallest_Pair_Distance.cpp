#include <bits/stdc++.h>
using namespace std;

/* 
Find the k-th smallest pair distance from an array
Brute force will be for loop twice to check every single pair and add it into a array and sort it, then we can find out the kth pair
Time complexity: O(n^2 + nlogn)

A more clever way will be using binary sort and sliding window (for determine the pair)
*/
class Solution{
    public:
        int smallestDistancePair(vector<int> &nums, int k) {

            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            
            // First we sort the array first to allow us to apply sliding window
            sort(nums.begin(), nums.end());
            int n = nums.size();

            // do binary sort to determine which pair will it be
            // range of binary sort (difference)
            int l = 0, r = nums[n - 1] - nums[0];

            function<int(int)> helper = [&](int m) {
                
                int cnt = 0;
                int left = 0, right = 0;

                for (; right < n; right++) {
                    
                    // adjust the window until all the pair of number within the window is less than the median
                    while (nums[right] - nums[left] > m)
                        left++;

                    // For every window we just update the number of pairs
                    cnt += right - left;                    
                }

                return cnt;
            };

            while (l < r) {

                int median = l + (r - l) / 2;
                int pair_cnt = helper(median);

            // we try to reduce the constraint for the sliding window with a much lower median value
                if (pair_cnt >= k)
                    r = median;
            // since is not even enough to gather until kth smallest, so we have to increase the median value
                else
                    l = median + 1;

            }            

            return l;
        }
};