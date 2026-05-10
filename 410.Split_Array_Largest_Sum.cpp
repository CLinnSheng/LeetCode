#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

class Solution
{
  public:
    int splitArray(std::vector<int> &nums, int k)
    {
        // Split nums into k non-empty subarrays such that the largest sum of any subarray is minimized
        // So now we need to find the maximum subarray sum that is minimized
        // So actually we seeing a range of value we can search for
        // From this, we can use binary search instead of linear search
        // So whats the minimum and maximum value of the range?
        // The minimum value will just simply be the largest element in the arrays because each array must have at least
        // 1 element Maximum value will just simply the sum of all elements as the subarray contain all the elements So
        // how does the 'k' affect here? So theres the binary search come over at this value, are we able to form k
        // value of subarray that have maximum sum of this value?

        int left = *std::max_element(nums.begin(), nums.end());
        int right = std::accumulate(nums.begin(), nums.end(), 0);

        const std::function<bool(int val)> helper = [&](const int val) {
            int size{1};
            int currSum{};

            for (const auto num : nums)
            {
                if (currSum + num > val)
                {
                    currSum = 0;
                    size++;
                }

                currSum += num;
            }
            return size <= k;
        };

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (helper(middle))
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return left;
    }
};
