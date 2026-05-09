#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
class Solution
{
  public:
    int shipWithinDays(std::vector<int> &weights, int days)
    {
        // Finding the least weight capacity so that can shipped within days
        // Each day we can put as many weight as we want as long as it didnt exceed the weights
        // So the worst case is just the sum of all the weights, so that we can ship it in 1 days
        // But the min range not 1 instead, the maximum element in the range because each ship must able to carry 1
        // weight So this hint that we actually trying to find the least within a `range`. Range --> We can use binary
        // search instead of linear search O(nlgm)

        int left = *std::max_element(weights.begin(), weights.end());
        int right = std::accumulate(weights.begin(), weights.end(), 0);

        // Helper function to check whether can we make it within days or not
        std::function<bool(const int weight)> helper = [&](const int weight) {
            int daysTaken{1};
            int remainingWeight{weight};

            for (auto const w : weights)
            {
                // Need another day
                if (remainingWeight - w < 0)
                {
                    daysTaken++;
                    remainingWeight = weight;
                }

                remainingWeight -= w;
            }
            return daysTaken <= days;
        };

        // Need to consider every possible range
        while (left < right)
        {
            int middle = left + (right - left) / 2;

            // Able to make it --> try finding smaller weight
            if (helper(middle))
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }

        return left;
    }
};
