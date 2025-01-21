#include <algorithm>
#include <climits>
#include <vector>

/*
 * Goal: Find the subarray with the largest sum and return its sum.
 *
 * Intuition:
 * By using brute force to find out every single possible subarray.
 * The time complexity is O(n^3) -> 3 for loops
 *
 * However if we see theres actually an overlapping of copmuting when trying out every single possible subarray.
 * eg: 2 1 4 3 5 6
 * subarray: [2], [2, 1], [2, 1, 4], [2, 1, 4, 3] ...
 * when we want to find out the sum of subarray [2, 1, 4] we dont actually has to reloop we just need to add the nums[i]
 * with the sum of the previous subarray. This will greatly reduced to O(n^2)
 *
 * Can we even further optimize this? yes
 * This intuition is come from the question which we trying to find the largest sum.
 * It can contain negatvie elements also.
 * What we gonna do is trying to be greedy, we try to avoid adding sum of negative element because it will make the sum
 * lesser. So everytime we compute a negative sum, we will recompute again from the current index. But how do we deal
 * with if every single element is negative? --> Then we just simply need to reset the sum every single time. So the
 * maximum size of the subarray only 1 which give the largest sum Time Complexity: O(n) Space Complexity: O(n)
 * */
class Solution
{
  public:
    int maxSubArray(std::vector<int> &nums)
    {
        int size(nums.size());
        if (size == 1)
            return nums[0];

        int currSum{}, maxSum{INT_MIN};
        for (const int &num : nums)
        {
            // if the sum from the previous subarray is already smaller than 0, we restart it
            // from the current element
            if (currSum < 0)
                currSum = 0;

            currSum += num;
            maxSum = std::max(maxSum, currSum);
        }
        return maxSum;
    }
};
