#include <algorithm>
#include <climits>
#include <vector>

/*
 * Goal: Find the subarray with the largest sum and return its sum.
 *
 * Intuition:
 * The brute force way will just simply be double loop to try out all every single possible subarray
 * But if we notice from the brute force, we are doing some repetition work as the subarray are overlapping
 *
 * We can actually be greedy when finding the subarray, so we will have a variable to keep track of the currSum.
 * So whenever the currSum is lesser than 0 we will just reset it back to 0, because is uesless to include previous
 * elements that already make the subarray sum less than 0. So the sum of the subarray wont be larger than the subarray
 * dont inlcude those Time Complexity: O(n^2)
 * */
class Solution
{
  public:
    int maxSubArray(std::vector<int> &nums)
    {
        int n(nums.size());
        if (n == 1)
            return nums[0];

        int currSum{}, answer{INT_MIN};

        for (const auto num : nums)
        {
            // Reset back to 0 if the current subarray already has a negative sum,
            // no point to continue and inlcude previous elements
            if (currSum < 0)
                currSum = 0;

            currSum += num;
            answer = std::max(answer, currSum);
        }
        return answer;
    }
};
