#include <map>
#include <vector>
using ll = long long;

/*
Goal: Return the maximum subarray sum 
Constraint: The elements in the subarray has to be distinct

Intuition: The naive approach will be very simple is just to scan through the array, and for every element we just need to scan its k neighbors. 
Time Complexity: O(n * k)

We can optimize this, why do we have to make a k window every time we scan through the array.
We can just use reuse the window by moving it.
The algorithm will be sliding window.
Since we have to take care of the elements of the subarray to be distinct, we can make use of
hash map data structure to keep track of the count and the size of the current window

Time Complexity: O(n)
Space Complexity: O(n)

Actually we can further optimize this by skipping keep scanning through window already has duplicate elements. When we encounter this for exmaple when k = 4 and the current window is 2 3 3 1 we can striaght away reduce the window to 3 1 by shifting the left pointer
*/
class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        ll sum{};    
        ll ans{};
        std::map<int, int> mp;
        int left{}, right{};

        while (right < nums.size()) {
            sum += nums[right];
            int currNum{nums[right]};

            int lastOccurenceIndex = mp.count(currNum) ? mp[currNum] : -1;
        
            while (left <= lastOccurenceIndex || right - left + 1 > k) {
                sum -= nums[left];
                left++;
            }

            if (right - left + 1 == k)
                ans = std::max(ans, sum);

            mp[currNum] = right++;
        }
        return ans;
    }
};