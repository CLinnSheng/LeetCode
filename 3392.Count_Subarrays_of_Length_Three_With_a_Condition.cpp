#include <vector>

/*
 * Goal: Return the number of subarrays of length 3 such that the sum of first and third numbers equal exactly half of
 * the second number.
 *
 * Intution: Just iterate through the array and compute the sum and compare
 * 1 important thing from the question is equal exactly
 * */
class Solution
{
  public:
    int countSubarrays(std::vector<int> &nums)
    {
        int cnt{};

        for (int i{}; i < nums.size() - 2; i++)
        {
            int sum{nums[i] + nums[i + 2]};
            if (sum == nums[i + 1] / 2.0)
                cnt++;
        }
        return cnt;
    }
};
