#include <climits>
#include <cmath>
#include <ios>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

/*
Given:
Robot start at point(0, 0). Can receive three possible types of commands:
-2 -> Turn left 90 degerees
-1 -> Turn right 90 degrees
1 <= k <= 9 -> Move forward k units, one unit at a time
Constraint: Got obstacles at some of the grid, ith obstacle is at grid point obstacles[i] = (xi, yi). If robot runs into an obstacle, will stay in its current location and move on the next command

Goal: Return the maximum Euclidean distance that the robot ever gets from the origin.
Intuition: Store the obstacles into a set data structure, so everytime we move a step we check whether this grid has obstacle or not
For hashing, we use at least twice the maximum value of coordinates 

Time Complexity: O(m + n)
`*/
class Solution
{
public:
    const std::vector<std::pair<int, int>> moves{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int MULTIPLIER = 6e4;
    
    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        std::pair<int, int> pos{0, 0};
        int direction = 0; // 0 - North, 1 - East, 2 - South, 3 - West
        int max_Area = INT_MIN;
        
        std::unordered_set<int> obstacle_coord;
        for (const auto& obstacle : obstacles)
            obstacle_coord.insert(obstacle[0] + MULTIPLIER * obstacle[1]);
        
        for (const auto& command : commands)
        {
            // Changing direction
            if (command < 0)
                direction = (command == -1)? (direction + 1) % 4 : (direction + 3) % 4;
            else 
            {
                std::pair<int, int> move = moves[direction];
                for (int i = 0; i < command; i++)
                {
                    int nextX = pos.first + move.first;
                    int nextY = pos.second + move.second;
                    
                    if (obstacle_coord.count(nextX + MULTIPLIER * nextY))
                        break;
                    
                    pos.first = nextX;
                    pos.second = nextY;
                }
                
                max_Area = fmax(max_Area, std::pow(pos.first, 2) + std::pow(pos.second, 2));
            }
        }
        
        return max_Area;
    }
};