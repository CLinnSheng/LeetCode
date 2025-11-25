/*
 * Intuition: Just simply shift right and use 'and'
 * Time Complexity: O(N)
 * */
class Solution
{
  public:
    int hammingWeight(int n)
    {
        int count{};

        while (n)
        {
            count += n & 1;
            n >>= 1;
        }

        return count;
    }
};
