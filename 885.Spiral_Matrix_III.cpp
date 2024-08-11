#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
Question: given number of rows and cols and the position for where we gonna start
We will be walking through all the cells by walking spirally
Goal: Return the coordinates of cell in the order we visited them

Intuition: The only way is to stimulate the process
theres a pattern on how to go through this spiral pattern
increase the steps size every 2 move
*/
    // the order is following how spiral step move
    // right, down, left, up
    const vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<int>> ans;

        for (int step_size = 1, direction = 0; ans.size() < cols * rows; step_size++)
            // Direction:
            // 0 --> right, 1 --> down
            // 2 --> left, 3 --> up
            
            // every 2 move we cahnge the step_size
            for (int i = 0; i < 2; i++) {
                // iterate through every single step
                for (int step = 0; step < step_size; step++) {
                    // check wether this cell exists or not, if exists we traverse
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                        ans.emplace_back(vector<int>{rStart, cStart});

                    auto [x, y] = dir[direction];
                    rStart += x;
                    cStart += y;
                }

                direction = (direction + 1) % 4;
            }
        

        return ans;
    }
};