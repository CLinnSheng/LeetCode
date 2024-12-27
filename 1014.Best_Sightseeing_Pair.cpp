#include <algorithm>
#include <vector>

/*
 * Given an integer array values where values[i] represent the value of the ith sightseeing spot.
 * 2 sightseeing spots i & j have a distance j - i between them.
 * Score of a pair where i < j is values[i] + values[j] + i - j.
 * which is the sum of the values of the sightseeing spots & minus the distance between them
 *
 * Goal: Return the maximum score of a pair of sightseeing spots
 *
 * Intuition:
 * The brute force way will be O(n^2) by using a nested loop
 *
 * How can we optimize it to O(n) or O(nlgn)?
 * To get the maximum score we need to maximize the sum & minimize the distance
 * How we can achieve this in a linear time?
 * A variable to hold the current maximum value to choose before the ith values.
 * Then keep update the the max score while iterate it through
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    int maxScoreSightseeingPair(std::vector<int> &values)
    {
        int ans{};
        // currMax holds the maximum value to be sum before the ith index
        // the -1 is the distance;
        int currMax{values[0] - 1};

        for (int i{1}; i < values.size(); i++)
        {
            // updates the maximum score pair
            ans = std::max(ans, currMax + values[i]);
            // updates the currMax
            // currMax - 1 (-1 is due to we move to the next index and the distance increase by 1 so we need to minus 1)
            currMax = std::max(currMax - 1, values[i] - 1);
        }

        return ans;
    }
};
