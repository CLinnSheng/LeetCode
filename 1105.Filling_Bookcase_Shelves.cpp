#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
Use dp
Here we use bottom up approach
*/
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = books.size();
        vector<int> dp(n+1, -1);

// At index 0 means no book were put, so height must be 0
        dp[0] = 0;

        for (int i = 1; i <= n; i++){
            int w = books[i - 1][0], h = books[i - 1][1];
            // we simply just add it up assume we put in a new shelf
            dp[i] = dp[i - 1] + h;

            for (int j = i - 1; j > 0; j--){
                // Now we try to see if we can put the current book and 
                // all the previous books in the same shelf or not
                w += books[j - 1][0];

                if (w > shelfWidth) break;

                // Checking the maximum height in the same shelf
                h = max(h, books[j - 1][1]);
                // update the ith book placed by comparing if straight put in a new row
                // vs putting in the previous row + new row
                dp[i] = min(dp[i], dp[j - 1] + h);
            }
        }

        return dp[n];
    }
};
