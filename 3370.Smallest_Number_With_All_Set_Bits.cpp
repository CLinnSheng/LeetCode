/*
 * Return the smallest number x greater than or equal to n such that x contain only set bits
 *
 * Intuition:
 * Simulation
 * */
#include <cmath>
class Solution
{
  public:
    int smallestNumber(int n)
    {
        int pow{};
        int val = std::pow(2, pow);

        while (val - 1 < n)
        {
            val = std::pow(2, ++pow);
        }
        return val - 1;
    }
};
