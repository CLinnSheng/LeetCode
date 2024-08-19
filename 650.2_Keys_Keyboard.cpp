#include <bits/stdc++.h>
using namespace std;
/*
Initially there is only on character, everytime we only allow to copy all the characters on the screen
So we need to find the minimum number of times to get the number of characters to n times
Intuition: Backtracking and dp (to reduce time complexity)
*/
class Solution {
    
    public:
        int minSteps(int n) {
            
            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            
            if (n == 1) return 0;
            
            // memo to store
            vector<vector<int>> dp(n + 1, vector<int>(n / 2 + 1, 0));

            function<int(int, int)> backtrack = [&](int cur_len, int paste_len) {

                // reach the desired length, no need to make any extra move
                if (cur_len == n)   return 0;
                // exceed the desired length, return the max possible number of steps
                if (cur_len > n) return 1000;

                // check the memo, if exists we can skip it
                if (dp[cur_len][paste_len]) return dp[cur_len][paste_len];
                
                // no copy & keep repeating paste the same length (takes only 1 move)
                int opt1 = 1 + backtrack(cur_len + paste_len, paste_len);

                // copy the current length and paste it (takes 2 move)
                int opt2 = 2 + backtrack(cur_len * 2, cur_len);

                dp[cur_len][paste_len] = min(opt1, opt2);

                return dp[cur_len][paste_len]; 
            };

            // + 1 because we include the move of copy the first character
            return 1 + backtrack(1, 1);
        }
};