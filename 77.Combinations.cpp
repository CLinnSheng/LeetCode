#include <functional>
#include <vector>
using std::vector;

/*
 * Goal: Return all possible combinations of k numbers chosen from the range [1, n]
 *
 * Intuition:
 * Just use recursive and backtrackking because we need to try all possible combination of k wihtin the range
 * */
class Solution
{
  public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> currSubset;
        vector<vector<int>> answer;

        std::function<void(const int &)> backtracking = [&](const int &val) {
            if (currSubset.size() == k)
            {
                answer.emplace_back(currSubset);
                return;
            }

            if (val > n)
                return;

            for (int i{val}; i <= n; i++)
            {
                currSubset.emplace_back(i);
                backtracking(i + 1);

                // backtracking
                currSubset.pop_back();
            }
        };
        backtracking(1);
        return answer;
    }
};
