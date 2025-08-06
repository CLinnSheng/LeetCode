#include <algorithm>
#include <functional>
#include <vector>
using std::vector;

/*
 * This is almost similar to the combinationSum1 but for this each element can only chose once
 * And also must not contain duplicate combinations. So every subset in the answer has to be unique
 *
 * Intuition:
 * Ok so to encounter the problem of unique combination we only need to handle when there exists 2 same element side by
 * side. We only do the recursion for one of the element is good enough
 * The unique combination is the element inside the combination must be unique regarding of the order.
 * Then we need to sort the array first, in order to eliminate the combination of getting the target with different
 * order Because the same element will be stick together and we will only perform the recursion only once
 *
 * TIme Complexity: O(n * 2^n)
 * */
class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> currSubset;
        vector<vector<int>> answer;
        std::sort(candidates.begin(), candidates.end());

        std::function<void(const int &, const int &)> backtracking = [&](const int &index, const int &currSum) {
            if (currSum == target)
            {
                answer.emplace_back(currSubset);
                return;
            }

            if (currSum > target || index >= candidates.size())
            {
                return;
            }

            for (int i{index}; i < candidates.size(); i++)
            {
                // Handle same element
                // We can use repeating element but must be unique combinations
                if (i > index && candidates[i] == candidates[i - 1])
                    continue;

                currSubset.emplace_back(candidates[i]);
                backtracking(i + 1, currSum + candidates[i]);

                // backtracking
                currSubset.pop_back();
            }
        };

        backtracking(0, 0);
        return answer;
    }
};
