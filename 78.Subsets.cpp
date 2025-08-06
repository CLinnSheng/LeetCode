#include <functional>
#include <vector>

/*
 * Find all the possible subsets
 *
 * Intuition:
 * This is actually a tree decision problem, at every index we can choose to include it or not
 * Is also a so called backtracking
 *
 * Time Complexity: O(n * 2^n)
 * is n * 2^n because every new branch will has it own tree decision
 * */
class Solution
{
  public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};

        std::vector<int> currSubset;
        std::vector<std::vector<int>> answer;
        std::function<void(const int &)> backtracking = [&](const int &index) {
            answer.emplace_back(currSubset);

            // Base Case to stop the recursion
            if (index == nums.size())
                return;

            for (int i{index}; i < nums.size(); i++)
            {
                currSubset.emplace_back(nums[i]);
                backtracking(i + 1);
                currSubset.pop_back();
            }
        };

        backtracking(0);
        return answer;
    }
};
