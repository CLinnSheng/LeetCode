#include <vector>

/*
 * Each lemonade cost $5. Customer can either pay $5, $10, or $20.
 * Then provide the correct change
 *
 * Goal: Check whether the change is correct for every customer?
 * Intuition: We need to be greedy when returning the change, so we try to give back the change in the largest note
 * possible
 * */
class Solution
{
  public:
    bool lemonadeChange(std::vector<int> &bills)
    {
        int n5{}, n10{}, n20{};

        for (int i{}; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                n5++;
            }
            else if (bills[i] == 10)
            {
                n10++;
                if (n5 > 0)
                {
                    n5--;
                }
                else
                {
                    return false;
                }
            }
            else if (bills[i] == 20)
            {
                n20++;
                if (n10 >= 1 && n5 >= 1)
                {
                    n10--;
                    n5--;
                }
                else if (n5 >= 3)
                {
                    n5 -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
