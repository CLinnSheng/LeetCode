#include <bits/stdc++.h>
#include <climits>
#include <unistd.h>
using namespace std;

/*
Given m * n matrix, maximimize the number of points by choosing from the matrix
1 from each row
Constraint: lose point if the cell picked is too far from prevoius row
(r, c1) -> (r + 1, c2) subtract abs(c1 - c2) from the score

Intuition: Since we want to find the best from each row and thus we can use dynamic programming to keep track
of the maximum points for choosing the current cell
for each row, we go through twice one is from the left to the right and another 1 is from the right to the left
and update the maximum point every time
*/
class Solution {
  
    public:
        long long maxPoints(vector<vector<int>>& points) {
            
            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            
            int n_col = points[0].size();
            vector<long long> curRow(n_col, 0), prevRow(n_col, 0);
            
            for (const auto &point : points) {
                
                // tracking the maximum point for choosing each cell
                long long curMax = 0;
                
                // from left to right (for picking cell from prev row)
                for (int  col = 0; col < n_col; col++) {
                    // Compare the current maximum with previous row to determine which cell to choose from previous row
                    curMax = max(curMax - 1, prevRow[col]);
                    curRow[col] = curMax;
                }
                
                curMax = 0;
                
                // from right to left (for picking cell from prev row)
                for (int col = n_col - 1; col >= 0; col--) {
                    // Same as above
                    curMax = max(curMax - 1, prevRow[col]);
                    curRow[col] = max(curMax, curRow[col]) + point[col];
                }
                
                prevRow = curRow;
            }
            
            // finding the maximum point from the last cell
            long long ans = INT_MIN;
            for (const auto &point : curRow)
                ans = max(ans, point);
                
            return ans;
        }
};