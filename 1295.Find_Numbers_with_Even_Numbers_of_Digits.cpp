#include <vector>

/*
 * Given an array of integers, nums
 * Goal: Return how many of them contain an even number of digits.
 *
 * Intuition:
 * The brute force will just simply go through the array and then check through every single element
 * Given that the nums largest is at 10^5
 * Time Complexity: O(6 * n) --> O(n) which is still ok
 *
 * */
class Solution
{
    bool isEvenDigit(int a)
    {
        int nDigit{};

        while (a)
        {
            nDigit++;
            a /= 10;
        }

        return nDigit % 2 ? false : true;
    }

  public:
    int findNumbers(std::vector<int> &nums)
    {
        int cnt{};

        for (const auto &num : nums)
            if (isEvenDigit(num))
                cnt++;

        return cnt;
    }
};
