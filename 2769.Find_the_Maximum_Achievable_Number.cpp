/*
 * Goal: Return the maximum possible value of x
 * A number x is achievable if it can become equal to num after applying opeartion at most t times.
 *
 * Intuition:
 * So we want to find out the maximum possible value of x after t operation it can be num
 * Take note that the opeartion can be +1/-1
 * So the best way would be increase both of them
 * */
class Solution
{
  public:
    int theMaximumAchievableX(int num, int t)
    {
        if (t < 1)
            return num;

        return num + t * 2;
    }
};
