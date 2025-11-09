/*
 * In 1 operation, if num1 >= num2, subtract num2 from num1 otherwise the otherway around
 * Goal: Return the number of operation to make either num1 = 0 or num2 = 0
 * */
class Solution
{
  public:
    int countOperations(int num1, int num2)
    {
        int cnt{};

        while (num1 != 0 && num2 != 0)
        {
            if (num1 >= num2)
            {
                num1 -= num2;
            }
            else
            {
                num2 -= num1;
            }
            cnt++;
        }
        return cnt;
    }
};
