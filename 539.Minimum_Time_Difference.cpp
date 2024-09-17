#include <ios>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

/*
Goal: Return the minimum time difference in minutes between any two time point in the list
Take Note: Time is cyclic means that the time difference between 2200 and 0100 is 3 while not 19

Intuition: Since we need to find the time difference in minutes, we first convert all the value and store into a sorted list
Since we know that the time will be distribute in the range of [0, 24 * 60 - 1] so is impossible for two teimstamp to have the same amount minutes if we meet it 
we straight return.
So from this we can think of using bucket sort. Since is bucket is gonna at most 1 and 2 for only 1 cases if they have the same timestamp (unifromly distribute)
So we gonna benefits from the best case time complexity of Bucket sort which is O(N)
Space Complexity: O(N)

Naive approach will be checking for every single element with double loop --> O(n^2)
We can also sort first and then check it adjacent elment but this takes O(nlgn)

REMEMBER: We need to take care 1 special case which is the time difference between the first timstamp and last timestamp because time is cyclic
*/

class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        // Creating a bucket
        std::vector<bool> buckets(24 * 60, false);

        for (const auto& time : timePoints)
        {
            auto hour_ = std::stoi(time.substr(0, 2));
            auto minute_ = std::stoi(time.substr(3));

            auto ttl_minute = hour_ * 60 + minute_;

            // if we encounter this before, that means the minimum difference is 0
            if (buckets[ttl_minute]) return 0;
            buckets[ttl_minute] = true;
        }

        // The data is uniformly distributed, so at now each bucket only have 1 data. So we dont have to do innert sort
        // So we will just go through each bucket --> Time Complexity: O(n) == Space Complexity

        int first_index = INT_MAX;
        int last_index = INT_MAX;
        int prev_index = INT_MAX;
        int ans = INT_MAX;

        for (int i = 0; i < 24 * 60; i++)
        {
            if (buckets[i])
            {
                if (prev_index != INT_MAX)
                    ans = std::min(ans, i - prev_index);
                
                prev_index = last_index = i;

                if (first_index == INT_MAX)
                    first_index = i;
            }
        }
        // Checking the first and last because of cyclic property of time
        return std::min(ans, 24 * 60 - last_index - first_index);
    }
};