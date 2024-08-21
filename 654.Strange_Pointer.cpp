#include <bits/stdc++.h>
using namespace std;
/*
Printer Features:
- Print a sequence of the same character at the same time
- Can print new characters starting from and ending at any place and will cover the orignal existing characters
eg : 1st step: print aaa
     2nd step : print b
     where the b will replace the middle a and produce aba

Goal: return the minimum number of turns

Brute Force: Will be printing every single character
Intuition: We will try to find a sequence that start and end with the same character
and use dp[i][j] that stores the minimum count to print the characters from i to j

For matching letters like a a a a x x
dp[i][j] = dp[i][k - 1] + dp[k + 1][j]
take notes that printing of 1a to 4a all takes only step so thats y
dp[i][i] = dp[i][i + 1] = ... = dp[i][k - 1] = dp[i][k]
*/
class Solution {
public:
    int strangePrinter(string s) {

        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = s.length();

        // dp[i][j] that stores the minimum count to print the characters from i to j
        vector<vector<int>> memo(n, vector<int>(n, -1));

        function<int(int , int)> helper = [&](int start, int end) {

            if (start > end)
                return 0;

            // check the memo
            if (memo[start][end] != -1)
                return memo[start][end];

            // worst case scenario, printing every single character
            int cnt = 1 + helper(start + 1, end);

            for (int k = start + 1; k <= end; k++)
                // if it is a repeated character, then we can make use of the printer features
                if (s[k] == s[start])
                    cnt = min(cnt, helper(start, k - 1) + helper(k + 1, end));

            return memo[start][end] = cnt;
        };

        return helper(0, n - 1);
    }
};
