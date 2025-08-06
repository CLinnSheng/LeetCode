#include <functional>
#include <set>
#include <vector>
using std::vector;

/*
 * Given an array nums that might contain duplicates
 * Goal: Return all possible unique permutation in any order
 *
 * Intuition:
 * Now the array contain duplcates how can we resolve this issues?
 * We can just use a hash set to track it
 * TIme Complexity: O()
 * */
class Solution
{
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n(nums.size());

        if (n == 0)
            return {};

        vector<int> currSubset;
        vector<int> used(n, false);
        std::set<vector<int>> answer;

        std::function<void()> backtracking = [&]() {
            if (currSubset.size() == n)
            {
                answer.insert(currSubset);
                return;
            }

            for (int i{}; i < n; i++)
            {
                if (used[i])
                    continue;

                currSubset.emplace_back(nums[i]);
                used[i] = true;
                backtracking();

                // backtracking
                currSubset.pop_back();
                used[i] = false;
            }
        };

        backtracking();
        return vector<vector<int>>(answer.begin(), answer.end());
    }
};
