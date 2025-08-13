/*
 * integer n is power of three, check if n is power of three
 * */
class Solution
{
  public:
    bool isPowerOfThree(int n)
    {
        // edge case
        if (n <= 0)
            return false;

        while (n)
        {
            if (n == 1)
                return true;

            if (n % 3)
                break;

            n /= 3;
        }
        return false;
    }
};
