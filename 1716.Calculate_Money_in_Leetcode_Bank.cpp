/*
 * Puts money into the bank every day.
 * Put 1$ more than the day before. But every subsequent Monday will put $1 more than the previous monday
 *
 * Intuition:
 * Just keep track of the money put on monday. Then restart the counting in the new week
 * */
class Solution
{
  public:
    int totalMoney(int n)
    {
        int answer{};
        int mondayMoney{1}, currMoney{1};
        int days{1};

        while (days <= n)
        {
            answer += currMoney;
            days++;

            // Handling the money
            if (days % 7 == 1)
            {
                mondayMoney++;
                currMoney = mondayMoney;
            }
            else
            {
                currMoney++;
            }
        }

        return answer;
    }
};
