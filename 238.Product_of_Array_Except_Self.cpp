#include <bits/stdc++.h>
using namespace std;

/*
Goal: Return an array answer such that answer[i] is equal to the product of all the terms except itself nums[i]
eg: [1, 2, 3, 4] -> [24, 12, 8, 6]

Brute force will take O(n2) by iterating the array twice which the second iteration skip itself
Intution: is it possible to use O(n) ---> Is the same traverse the array twice but not inner for loop
First traverse the array from the left and second time from the right

Dry Run:
[1, 2, 3, 4] Ans (initial) = [1, 1, 1, 1]
left: [1, 1, 2, 6]
right: [24, 12, 4, 1]
*/

class Solution {
    
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            
            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            
            int n = nums.size();
            vector<int> ans(n, 1);
            int postfixSum = 1;
            
            // Traverse from the left
            for (int i = 1; i < n; i++)
                ans[i] = ans[i -1 ] * nums[i - 1];
                
            for (int i = n - 1; i >= 0; i--){
                ans[i] *= postfixSum;
                postfixSum *= nums[i];
            }
            
            return ans;
        }
};