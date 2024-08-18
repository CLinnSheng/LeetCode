#include <bits/stdc++.h>
using namespace std;

/*
An ugly number is a product (2, 3, 5) of the previous ugly number
Theres 2 way:
1st way is by using min heap
we produce the ugly number from the min number every time 
and use a set to keep track of the number produced to prevent duplicate
time complexity: O(n log m) --> each push & pop for heap will be result in log m and we will be doing it for n times

2nd way is by using DP
Instead of using array to store, we optimize it by just using pointer
we will have 3 pointers for 2, 3 & 5
Same we will produce the smallest number each time just like heap from factor of 2, 3 & 5
for ugly number that will produce the same ugly number, we will move both the pointer at the same time
*/
class Solution {
    
    public:
    int nthUglyNumber(int n) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int pointer_2, pointer_3, pointer_5;
        pointer_2 = pointer_3 = pointer_5 = 0;
        
        // Have a vector to store the ugly number
        vector<int> ugly_nums(n);
        ugly_nums[0] = 1;
        
        for (int i = 1; i < n; i++) {
            
            int ugly_num = min(ugly_nums[pointer_2] * 2, 
                               min(ugly_nums[pointer_3] * 3, ugly_nums[pointer_5] * 5));
            ugly_nums[i] = ugly_num;
            
            // moving the pointer
            if (ugly_num == ugly_nums[pointer_2] * 2)   pointer_2++;
            if (ugly_num == ugly_nums[pointer_3] * 3)   pointer_3++;
            if (ugly_num == ugly_nums[pointer_5] * 5)   pointer_5++;
            
        }
        
        return ugly_nums[n - 1];
    }        
    
};