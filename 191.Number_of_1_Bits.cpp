#include <cstdint>
/*
 * Find out the number of 1 bits, simply just 'AND' with 1 & keep shifting to the right
 * */
class Solution
{
  public:
    int hammingWeight(uint32_t n)
    {
        int ans{};
        while (n)
        {
            if (n & 1)
            {
                ans++;
            }

            n >>= 1;
        }

        return ans;
    }
};
