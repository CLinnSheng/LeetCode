/*
 * A factor of an integer n is defined as an integer i where n % i == 0
 * Goal: Consider a list of all factors of n in ascending order, return the kth factor i this list or return -1 if n has
 * less than k factors.
 *
 * Intuition:
 * Just iterate through all possible single factor from the lowest
 * */
class Solution
{
  public:
    int kthFactor(int n, int k)
    {
        int cnt{};

        for (int i{1}; i <= n; i++)
        {
            if (n % i == 0)
                cnt++;

            if (cnt == k)
                return i;
        }
        return -1;
    }
};
