class Solution
{
  public:
    long long coloredCells(int n)
    {
        long long addCells{4}, ttlCells{1};
        while (--n)
        {
            ttlCells += addCells;
            addCells += 4;
        }
        return ttlCells;
    }
};
