#include <bits/stdc++.h>
using namespace std;
/*
Given an m arrays and is sorted in ascending order
Need to pick 2 integers from 2 different arrays and calculate the distance (abs diff)
return the maximum distance

Intuition: Only care about the min and max from every single array
array[0] min and array[size - 1] max
brute force will be O(n^2) by just comparing every single array come after it

use greedy solution by keep updating the min, max, and maximum distance for every array we iterate
#include <functional>
#include <ios>
#include <iostream>
#include <vector>
#include <utility>

/*
Goal: Return the number of islands in grid2 that are considered sub-islands
An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2
Intuition: First we flood fill the grid2 with respect to grid1 for checking whether that subisland is a legit subisland or not
by using dfs & recursive approach to serach through grid2
Time Complexity: O(n2)
*/
class Solution {
    
    public:
        const std::vector<std::pair<int, int>> direction{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {

            std::ios_base::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
            
            int n_rows = grid1.size(), n_cols = grid1[0].size();
            int n_subIsland = 0;
            
            // Keep track of the visited cells
            std::vector<std::vector<bool>> visited(n_rows, std::vector<bool>(n_cols, false));
            
            std::function<bool(int, int)> checkSubIsland = [&](int r, int c) {
                
                bool isSubIsland = true;
                
                // Check whether the current cell in grid2 is exist in grid1 or not
                if (grid1[r][c] == 0)
                    isSubIsland = false;
                
                
                // dfs from this cell
                for (const auto& [x, y] : direction) {
                    int new_r = r + x;
                    int new_c = c + y;
                    
                    // dfs and check the boundary, visited before or not and whether is it an island
                    if (new_r >= 0 && new_c >= 0 && new_r < n_rows && new_c < n_cols && !visited[new_r][new_c] && grid2[new_r][new_c]) {    
                        visited[new_r][new_c] = true;
                        
                        // dfs & recursively call until to check whether all the cell in this subisland is subset of the subisland in grid1 or not
                        isSubIsland = isSubIsland && checkSubIsland(new_r, new_c);
                    }
                }
                
                return isSubIsland;
            };
            
            for (int i = 0; i < n_rows; i++)
                for (int j = 0; j < n_cols; j++) 
                    // dfs through grid2
                    if (grid2[i][j] && !visited[i][j]) {
                        // mark this cell visited
                        visited[i][j] = true;
                        
                        // check whether is this a legit subisland
                        if (checkSubIsland(i, j))
                            n_subIsland++;
                            
                    }
            return n_subIsland;
        }
        
};
            
            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            
            int cur_min = arrays[0].front(), cur_max = arrays[0].back();
            int ans = INT_MIN;
            
            for (int i = 1; i < arrays.size(); i++) {
                // this will prevent compute from the same array by starting from the second array
                ans = max(ans, max(arrays[i].back() - cur_min, cur_max - arrays[i].front()));
                
                cur_min = min(cur_min, arrays[i].front());
                cur_max = max(cur_max, arrays[i].back());
            }
            
            return ans;
        }
};