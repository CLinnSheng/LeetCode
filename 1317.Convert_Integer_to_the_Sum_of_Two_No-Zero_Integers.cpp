#include <vector>
/*
 * Goal :return a list of 2 integers [a, b] where  a & b are non-zero integers & = n
 *
 * Intuition:
 * the largest n is only 1e4, so by brute force wont TLE
 * */
class Solution
{
  private:
    bool checkZero(int n)
    {
        while (n)
        {
            if (n % 10 == 0)
                return true;

            n /= 10;
        }
        return false;
    }

  public:
    std::vector<int> getNoZeroIntegers(int n)
    {
        for (int i{1}; i < n; i++)
        {
            int complement_i{n - i};
            if (checkZero(i) || checkZero(complement_i))
                continue;

            return {i, complement_i};
        }
        return {};
    }
};
