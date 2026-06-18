#include <vector>
/*
 * Town Judge exists
 * - trusts nobody
 * - everybody trust town judge
 *
 * Goal is to find out the town judge
 * Create an inDegree & outDegree for each person
 * Then iterate through and find out the judge
 * */
class Solution
{
  public:
    int findJudge(int n, std::vector<std::vector<int>> &trust)
    {
        std::vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);

        for (const auto &a : trust)
        {
            inDegree[a[1]]++;
            outDegree[a[0]]++;
        }

        int index{-1}, judge{};

        for (int i{1}; i <= n; i++)
        {
            if (outDegree[i] == 0 && inDegree[i] == n - 1)
            {
                index = i;
                judge++;
            }
        }
        return judge == 1 ? index : -1;
    }
};
