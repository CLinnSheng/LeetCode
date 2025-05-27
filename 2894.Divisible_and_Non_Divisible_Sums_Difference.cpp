/*
 * num1: sum of all integers in the range[1,n] that are not divislbe by m
 * num2: sum of all integers in the range[1,n] that are divisble by m
 *
 * Goal: Return the integer num1 - num2;
 *
 * Intuition:
 * Just simply go through from 1 to n
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int differenceOfSums(int n, int m)
    {
        int ans{};

        for (int i{1}; i <= n; i++)
            ans += i * ((i % m) ? 1 : -1);

        return ans;
    }
};
