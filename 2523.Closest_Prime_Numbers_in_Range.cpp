#include <cmath>
#include <vector>
using std::vector;

/*
 * Find the 2 integers such that
 * num2 - num1 is the minimum amongst all other pairs
 * Then return the one with the smallest num1 value.
 *
 * Intuition:
 * We just need to find all the prime number within the range left & right.
 * And then just find the num1 and num2 with minimum.
 *
 * Time Complexity: O(n^2)
 * */
class Solution
{
  private:
    // O(n^2)
    vector<bool> sieveAlgo(const int &upperLimit)
    {
        // assume all are prime numbers initially
        vector<bool> sieve(upperLimit + 1, true);

        // 0 & 1 are not prime numbers
        sieve[0] = false;
        sieve[1] = false;

        for (int num{2}; num * num <= upperLimit; num++)
            // mark all multiples of prime number to false
            if (sieve[num])
            {
                for (int multiple{num * num}; multiple <= upperLimit; multiple += num)
                    sieve[multiple] = false;
            }

        return sieve;
    }

  public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> sieveArray{sieveAlgo(right)};
        vector<int> primeNumbers;

        for (int num{left}; num <= right; num++)
            if (sieveArray[num])
                primeNumbers.emplace_back(num);

        if (primeNumbers.size() < 2)
            return {-1, -1};

        vector<int> result{-1, -1};
        int diff{right - left + 1};
        for (int i{1}; i < primeNumbers.size(); i++)
            if (primeNumbers[i] - primeNumbers[i - 1] < diff)
            {
                diff = primeNumbers[i] - primeNumbers[i - 1];
                result = {primeNumbers[i - 1], primeNumbers[i]};
            }

        return result;
    }
};
