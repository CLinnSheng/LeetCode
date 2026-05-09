#include <algorithm>
#include <cmath>
#include <vector>
class Solution
{
  public:
    int minEatingSpeed(std::vector<int> &piles, int h)
    {
        // Determining the eating rate and find the minimum rate
        // such that we can eat all the bananas within h hours
        // Worst case the eating rate will just simply be the maximum number of bananas in all the piles
        // From here we can see the possible eating rate will just simply be in [1, max(banana)]
        // Since we need to find from a range, binary search will just simply win over a linear search
        // O(nlgm)

        // Finding the right boundary
        int right = *std::max_element(piles.begin(), piles.end());
        int left{1};
        int answer = right;

        while (left < right)
        {
            int middle = left + (right - left) / 2;

            // Calculating the hours taken
            int timeTaken{};
            for (const auto pile : piles)
            {
                timeTaken += std::ceil((pile / (double) middle));
            }

            if (timeTaken <= h)
            {
                answer = middle;
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
