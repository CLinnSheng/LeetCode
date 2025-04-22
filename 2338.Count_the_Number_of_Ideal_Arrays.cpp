/*
 * An array of length n is ideal if:
 * i. every arr[i] is a value from 1 to maxValue
 * ii. every arr[i] is divisible by arr[i - 1]
 *
 * Goal: Return the number of distinct ideal arrays of length n
 *
 * Intuition:
 * Observation:
 * 1 important observation is array with all elements with the same value is an ideal.
 * So we will have 1 to maxValue of ideal array with just this kind of pattern of array.
 * Another key observation is the array is increasing because we need arr[i] is divisible by arr[i - 1].
 * Also each element is a multple of previous one.
 * This is equivalent to counting non-decreasing sequence of factors.
 * */
#include <algorithm>
#include <cmath>
#include <cstring>
class Solution
{
  private:
    static const int MOD = 1e9 + 7;   // Modulo constant for preventing overflow
    static const int MAX_N = 10004;   // Maximum array size for precomputation
    static const int MAX_UNIQUE = 15; // Maximum unique prime factors expected

    // Precomputed primes less than 100 (covers factors of numbers ≤10000)
    static constexpr int PRIMES[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                                     43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    static const int PRIME_COUNT = sizeof(PRIMES) / sizeof(PRIMES[0]);

    // Precomputed combinations using Pascal's identity: C(n,k) = C(n-1,k-1) + C(n-1,k)
    static int C[MAX_N][MAX_UNIQUE];
    static bool initialized; // Flag to check if combinations are precomputed

    // Memoization cache for dynamic programming results
    static unsigned dp[10005];

    // Initialize combinations using Pascal's triangle
    static void initCombinations()
    {
        if (initialized)
            return;

        C[0][0] = 1; // Base case: C(0,0) = 1
        for (int i = 1; i < MAX_N; i++)
        {
            C[i][0] = 1; // C(i,0) = 1 for all i
            for (int j = 1; j <= std::min(MAX_UNIQUE - 1, i); j++)
            {
                // Pascal's identity with modulo
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
        initialized = true;
    }

    // Count the number of ideal arrays ending with x
    static int countWays(int x, const int n)
    {
        if (dp[x] != 0)
            return dp[x]; // Return cached result if available
        if (x <= 1)
            return dp[x] = 1; // Base case: only one way for 1

        // Check if x is a precomputed prime
        for (int i = 0; i < PRIME_COUNT; i++)
        {
            if (x == PRIMES[i])
                return dp[x] = n; // C(n,1) = n ways for primes
        }

        long long cnt = 1;         // Initialize count
        int x0 = x;                // Temporary variable for factorization
        int x_sqrt = std::sqrt(x); // Only need to check factors up to sqrt(x)

        // Factorize using precomputed primes
        for (int i = 0; i < PRIME_COUNT && PRIMES[i] <= x_sqrt; i++)
        {
            int p = PRIMES[i];
            if (x0 % p != 0)
                continue;

            int exp = 0; // Count exponent of prime factor
            while (x0 % p == 0)
            {
                exp++;
                x0 /= p;
            }

            // Handle cases where combination might overflow precomputation
            if (n - 1 + exp >= MAX_N)
            {
                // Calculate combination on the fly using multiplicative formula:
                // C(n+e-1, e) = product_{k=1}^e (n+k-1)/k
                long long comb = 1;
                for (int k = 0; k < exp; k++)
                {
                    comb = (comb * (n + k)) % MOD;
                    comb = (comb * modInverse(k + 1, MOD)) % MOD;
                }

                cnt = (cnt * comb) % MOD;
            }
            else
            {
                // Use precomputed combination
                cnt = (cnt * C[n - 1 + exp][exp]) % MOD;
            }
        }

        // Handle remaining prime factor > sqrt(x)
        if (x0 > 1)
        {
            cnt = (cnt * n) % MOD; // C(n,1) = n for single remaining prime
        }

        return dp[x] = cnt; // Cache and return result
    }

    // Modular inverse using Fermat's little theorem: a^{-1} ≡ a^{m-2} mod m
    static long long modInverse(long long a, long long m)
    {
        return modPow(a, m - 2, m);
    }

    // Fast exponentiation: a^b mod m using binary exponentiation
    static long long modPow(long long a, long long b, long long m)
    {
        long long res = 1;
        a = a % m;
        while (b > 0)
        {
            if (b & 1) // If b is odd
                res = (res * a) % m;
            b = b >> 1;      // b = b/2
            a = (a * a) % m; // Square a
        }
        return res;
    }

  public:
    static int idealArrays(int n, int maxValue)
    {
        initCombinations(); // Initialize combination table

        std::memset(dp, 0, sizeof(dp)); // Reset memoization cache

        long long ans = 0;
        for (int x = 1; x <= maxValue; x++)
        {
            ans = (ans + countWays(x, n)) % MOD; // Sum ways for all x ≤ maxValue
        }

        return ans;
    }
};

// Initialize static members
bool Solution::initialized = false;
int Solution::C[Solution::MAX_N][Solution::MAX_UNIQUE] = {{0}};
unsigned Solution::dp[10005] = {0};
