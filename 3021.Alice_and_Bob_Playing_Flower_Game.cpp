/*
 * x in first and y in the 2nd lane
 * Game Rules:
 * i. Alice take the turn first
 * ii. Each turn a player must choose either one of the lane and pick one from tat side
 * iii. End of the turn, if there are no flowers, the current player wins the game
 *
 * Goal: Return the number of possible pairs (x, y) satisfy the condition
 *
 * Intuition:
 * Alice must win the game, and thus alice must be the last the last 1 that pick the flower
 * Therefor, the total number of flower must be odd
 * Just basically find out all the possible combination of summing up to odd
 * */
class Solution
{
  public:
    long long flowerGame(int n, int m)
    {
        if (n == 1 && m == 1)
            return 0;

        return ((long long)n * m) / 2;
    }
};
