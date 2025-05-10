#include <vector>

/*
 * Replace all the 0's in both arrays with positive integers only such that the sum of all elements from both arrays
 * become equal
 *
 * GoaL: Return the minimum sum otherwise return -1
 *
 * Intuition:
 * Ok How about we assume all the zero is 1 first. Then after we only consider how can we change the 0's value minimumly
 * to achieve the exact amount of sum from both array
 * We need to check some edge cases as well like what if the smaller array dont have any 0s?
 *
 * But how do we know which value to place in all the 0s?
 * Ok lets be greedy and always choose the smallest number to fill in, since we must fill all the 0 with positive
 * integer So we filled with 1. Then just get the total sum from the larger array, because we dont really need to know
 * what value to fill in, we just only need to make sure that both array must be equal. So the smaller array will fill
 * whatever value it needed to reach the total sum from the larger array given that it has the 0s value.
 *
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    long long minSum(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        long long gotZero1{}, gotZero2{};
        long long sum1{}, sum2{};

        for (const auto &num : nums1)
        {
            sum1 += num;
            if (num == 0)
            {
                gotZero1++;
                sum1++;
            }
        }
        for (const auto &num : nums2)
        {
            sum2 += num;
            if (num == 0)
            {
                gotZero2++;
                sum2++;
            }
        }

        if ((!gotZero1 && sum1 < sum2) || (!gotZero2 && sum1 > sum2))
            return -1;

        return std::max(sum1, sum2);
    }
};
