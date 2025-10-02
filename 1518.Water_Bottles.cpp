/*
 * Can exchange numExchange empty water bottles from the market with one full water bottle
 *
 * Intuition:
 * Just do the math
 * */
class Solution
{
  public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ttl{};
        int numEmpty{};
        while (numBottles)
        {
            ttl++;
            numBottles--;
            numEmpty++;

            if (numEmpty == numExchange)
            {
                numEmpty = 0;
                numBottles++;
            }
        }
        return ttl;
    }
};
