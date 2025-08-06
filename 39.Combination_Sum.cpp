#include <functional>
#include <vector>
/*
 * Goal: Return a list of combinations in any order that will achieve the target
 *
 * Intuition:
 * Same this is a tree decision problem at every index we can choose to include it or not.
 * But we also need to include all possible subset, so we need backtracking
 * The base case to end the recursion is when it reach the target or exceed
 *
 * Time Complexity: O(2^n)
 * */
class Solution
{
  public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
    {
        std::vector<int> currSubset;
        std::vector<std::vector<int>> answer;

        std::function<void(const int &, const int &)> backtracking = [&](const int &index, const int &currSum) {
            if (currSum == target)
            {
                answer.emplace_back(currSubset);
                return;
            }

            if (currSum > target)
                return;

            for (int i{index}; i < candidates.size(); i++)
            {
                currSubset.emplace_back(candidates[i]);
                backtracking(i, currSum + candidates[i]);

                // backtracking
                currSubset.pop_back();
            }
        };

        backtracking(0, 0);
        return answer;
    }
};
