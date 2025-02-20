#include <algorithm>
#include <climits>
#include <vector>
using std::vector;

/*
 * Goal: Return the least weight capcity of the ship that will result in all the packages on the conveyor belt being
 * shipped within days days.
 *
 * Intuition:
 * Instead of saying how many days, maybe we can use how many ship instead. To find out the least weight capcity and
 * able to have least ships than the "days" The minimum weight capcity of a ship will be the min(weights) From getting
 * the minimum weight, it give me the instinct to use binary search where the maximum capcity is the sum(weights) where
 * u need only 1 ship to ship all weight
 *
 * Time Complexity: O(nlgs)
 *
 * */
class Solution
{
  private:
    bool helper(const int &capacity, const vector<int> &weights, const int &days)
    {
        int numShip{1};
        int currCapacity{capacity};
        for (const auto &weight : weights)
        {
            if (currCapacity - weight < 0)
            {
                numShip++;
                currCapacity = capacity;
            }
            currCapacity -= weight;
        }
        return numShip <= days;
    }

  public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int minWeight{INT_MIN}, maxWeight{};
        for (const auto &weight : weights)
        {
            minWeight = std::max(minWeight, weight);
            maxWeight += weight;
        }

        int answer{maxWeight};
        while (minWeight <= maxWeight)
        {
            int capacity(minWeight + (maxWeight - minWeight) / 2);
            if (helper(capacity, weights, days))
            {
                answer = std::min(answer, capacity);
                maxWeight = capacity - 1;
            }
            else
                minWeight = capacity + 1;
        }
        return answer;
    }
};
