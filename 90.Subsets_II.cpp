#include <algorithm>
#include <functional>
#include <vector>
using std::vector;

/*
 * Goal: Return all possible subsets and do not contain duplicate subsets
 *
 * Intuition:
 * How can we deal with duplicate subsets?
 * We can sort it first and then is much more easier to handle if the same element is next to each other
 * And then this is also a tree decision problem where at eveery index we ccan choose to include it or not
 * So we can use recursion and backtracking because we need to try all possible subset
 * Time Complexity: O(n * 2^n)
 */
class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n(nums.size());

        if (n == 0)
            return {};

        vector<vector<int>> answer;
        vector<int> currSubset;

        std::sort(nums.begin(), nums.end());

        std::function<void(const int &)> backtracking = [&](const int &index) {
            answer.emplace_back(currSubset);

            for (int i{index}; i < n; i++)
            {
                if (i > index && nums[i] == nums[i - 1])
                    continue;

                currSubset.emplace_back(nums[i]);
                backtracking(i + 1);

                // backtracking
                currSubset.pop_back();
            }
        };

        backtracking(0);
        return answer;
    }
};
