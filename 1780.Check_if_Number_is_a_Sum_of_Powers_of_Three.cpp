/*
 * Goal: Return true if it is possible to represent n as the sum of distinct powers of three.
 *
 * Intuition:
 * If we observer clearly, this is actually a decision tree problem. At every index
 * we can eitehr want to include or not. In this case is actually want to include the power of three or not.
 * How do we determine we cannot compute it? --> When the current sum is acutally greater or current power of three is
 * greater than target
 * Time Complexity:
 * We only need to consider the power of 3 which is 3^i <= target
 * so 3^i = n
 * therefore i will be log3n
 * Hence, O(2^log3n) --> at worst will be O(n)
 * */
#include <cmath>
#include <functional>
class Solution
{
  public:
    bool checkPowersOfThree(int n)
    {
        std::function<bool(const int &, const int &)> helper = [&](const int &power, const int &currSum) {
            if (currSum == n)
                return true;

            if (currSum > n || std::pow(3, power) + currSum)
                return false;

            // include or not include
            return helper(power + 1, currSum + std::pow(3, power)) || helper(power + 1, currSum);
        };
        return helper(0, 0);
    }
};
