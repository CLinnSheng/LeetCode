#include <functional>
#include <vector>
using std::vector;

/*
 * Return all possible combinations of k numbers chosen from the range [1, n]
 * NOTE: [2, 1] & [1, 2] are the same
 *
 * Intuition:
 * Use dfs & backtracking. It is a tree decision problem on whether want to include or not
 * */
class Solution
{
  public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> answer;

        std::function<void(vector<int> &, const int &)> dfs_backtracking = [&](vector<int> &temp, const int &currVal) {
            if (temp.size() == k)
            {
                answer.emplace_back(temp);
                return;
            }

            if (currVal > n)
                return;

            // Include
            temp.emplace_back(currVal);
            dfs_backtracking(temp, currVal + 1);
            // backtracking
            temp.pop_back();
            dfs_backtracking(temp, currVal + 1);
        };
        vector<int> temp;
        dfs_backtracking(temp, 1);
        return answer;
    }
};
