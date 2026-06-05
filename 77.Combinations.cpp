#include <functional>
#include <vector>
/*
 * Find all the combination of k number
 * So in simply words just from 1 to n we can either choose it or not
 * Backtracking --> O(2^n)
 * */
class Solution
{
  public:
    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<int> subset;
        std::vector<std::vector<int>> ans;

        std::function<void(const int)> backtracking = [&](const int index) {
            // Basecase
            if (subset.size() == k)
            {
                ans.emplace_back(subset);
                return;
            }

            if (index > n)
            {
                return;
            }

            for (int i{index}; i <= n; i++)
            {
                subset.emplace_back(i);
                backtracking(i + 1);
                subset.pop_back();
            }
        };

        backtracking(1);
        return ans;
    }
};
