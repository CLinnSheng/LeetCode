/*
 * In one operation:
 * i. Drink any number of full water bottles turning them into empty bottles.
 * ii. Exchange numExchange bottles with one full water bottle.
 *
 * Goal: Return the maximum number of water bottles you can drink
 * NOTE: You cannot exchange multiple batches of empty bottles for the same value of numExchange
 *
 * Intuition:
 * Just run the stimulation and be greedy to drink the most water bottles
 *
 * */
class Solution
{
  public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int res{};
        int numEmptyBottles{};

        while (numBottles)
        {
            res += numBottles;
            numEmptyBottles += numBottles;
            numBottles = 0;

            if (numEmptyBottles >= numExchange)
            {
                numEmptyBottles -= numExchange;
                numBottles++;
                numExchange++;
            }
        }

        return res;
    }
};
