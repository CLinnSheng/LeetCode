/*
 * A digit string is good if the digit at even indices are even and digit at odd indices
 * are prime (2,3,5,7)
 *
 * Goal: Return the total number of good digit strings of length n.
 *
 * Intuition:
 * We need to find out the length and find out the number of even indices and odd indicies.
 * Just apply permutations for even indices we have 5 choice and odd indices we have 4 choies
 * To handle overflow, we need a custom power function that will mod the value everytime we increases it and can solve
 * it in logn
 * Time Complexity: O(lgn)
 * */

#include <cmath>
#include <functional>
class Solution
{
  public:
    const int MOD = 1e9 + 7;
    int countGoodNumbers(long long n)
    {

        if (n == 1)
            return 5;

        long long evenIndicesCnt{(n + 1) / 2};
        long long oddIndicesCnt{n / 2};

        std::function<long long(long long, long long &)> powerMod = [&](long long base, long long &power) {
            // use fast exponential to calculate the pow
            // so instead of 5^25 times 5 25times we can keep it simple by keep dividing it by half
            // the idea behind is like this for example 2^8 we keep splitting it half all the way until 0
            // 2^8 = (2^2)4 = (4^2)2 = (16^2)1

            long long res{1};

            while (power > 0)
            {
                // deal with odd power
                if (power % 2)
                    res = (res * base) % MOD;

                base = (base * base) % MOD;
                power /= 2;
            }

            return res;
        };

        return (powerMod(5, evenIndicesCnt) * powerMod(4, oddIndicesCnt)) % MOD;
    };
};
