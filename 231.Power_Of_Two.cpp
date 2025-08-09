#include <cmath>
class Solution
{
  public:
    bool isPowerOfTwo(int n)
    {
        if (!n)
            return false;

        long long val{}, power{};

        while (val <= n)
        {
            if (n == val)
                return true;
            val = std::pow(2, power++);
        }
        return false;
    }
};
