#include <bits/stdc++.h>
using namespace std;

/*
array piles is a list of piles containing number of stones piles[i]
goal: end with the most stones for alice
Alice start first, everytime the player can choose from n piles from previous player to 2n
intuition: dynamic programming and min_max
*/
class Solution {
    
    public:
        int stoneGameII(vector<int>& piles) {
            
            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            
            int n_piles = piles.size();
            
            // this array stores the number of stones available at each position
            vector<int> suffixSum(n_piles + 1, 0);
            for (int i = n_piles - 1; i >= 0; i--)
                suffixSum[i] = suffixSum[i + 1] + piles[i];
                
            // memo for dynamic programming
            // the first dimension is to indicate strating from which index
            // the second dimension is to indicate the number of piles to take in the previous turn
            vector<vector<int>> memo(n_piles, vector<int>(n_piles + 1, 0));
            
            function<int(int, int)> maxStone = [&](int m, int current_pile) {
              
                // out of bound, no more piles to take
                if (current_pile >= n_piles)
                    return 0;
                    
                // if we can take all piles then take all piles
                if (current_pile + 2 * m >= n_piles)
                    return suffixSum[current_pile];
                    
                // if we encounter this before, straight away look form the memo
                if (memo[current_pile][m])
                    return memo[current_pile][m];
                    
                int maxStones = 0;
                
                // explore all possible choices through recursive call at each step
                for (int i = 1; i <= 2 * m; i++) {
                    // calculate the maximum number of stone alice can get in this turn
                    // number of stones that avilable from this pile to the last minus with
                    // what bob will get
                    int current_stone = suffixSum[current_pile] - maxStone(max(m ,i), current_pile + i);
                    maxStones = max(current_stone, maxStones);
                }
                
                memo[current_pile][m] = maxStones;
                return maxStones;
                    
            };
            
            return maxStone(1, 0);
        }
}
