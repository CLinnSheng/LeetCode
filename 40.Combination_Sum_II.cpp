#include <algorithm>
#include <functional>
#include <vector>
using std::vector;

/*
 * Finding the all the subset the sum up to target
 * But one constraint, the subset must be a unique combinations which means the order doesnt matter but the combination
 * does
 * So we need to handle the same number
 * To make thing easier we can just sort it first, so we can easily skip those same number
 * */
class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;

        std::function<void(const int, const int)> backtracking = [&](const int index, const int currSum) {
            // Base Case
            if (currSum == target)
            {
                ans.emplace_back(subset);
                return;
            }

            // Base Case + Check Duplicate Element
            if (currSum > target || index == candidates.size())
            {
                return;
            }

            for (int i{index}; i < candidates.size(); i++)
            {
                if (i > index && candidates[i] == candidates[i - 1])
                {
                    continue;
                }

                subset.emplace_back(candidates[i]);
                backtracking(i + 1, currSum + candidates[i]);
                subset.pop_back();
            }
        };

        backtracking(0, 0);
        return ans;
    }
};
