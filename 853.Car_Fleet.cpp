#include <bits/stdc++.h>
using namespace std;

/*
Intuition: Find number of car fleet at target miles
Take notes that each car started at different position and going at different speed
We must try to sort it according to the positions and check their arrived time for each car
and compare between cars
use a stack to store the time to reach the target miles

*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = position.size();
        vector<pair<int, int>> car;

        for (int i = 0; i < n; i++)
            car.emplace_back(make_pair(position[i], speed[i]));

        sort(car.begin(), car.end());
        deque<float> stack;

        for (int i = 0; i < n; i++) {
            float time =  (target - car[i].first) / (float(car[i].second));

            if (stack.empty()) {
                stack.emplace_back(time);
                continue;
            }

// if the car at of this position takes longer time than previous car then it will form a fleet
            while (!stack.empty() && time >= stack.back())
                stack.pop_back();

            stack.emplace_back(time);
        }

        return stack.size();
    }
};