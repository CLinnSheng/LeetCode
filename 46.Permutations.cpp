#include <functional>
#include <unordered_set>
#include <vector>
/*
 * Return all the permutation from an array of unique integers
 * So the order doesnt matter, we need to return all possible sequence of array
 * So we need a hashset to track which index of nums being used as we always start from index 0
 * So at every index we still deciding include it or not
 * Time Complexity: O(n * n!)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<int> subset;
        std::vector<std::vector<int>> ans;
        std::unordered_set<int> set;

        std::function<void()> backtracking = [&]() {
            // Base Case
            if (subset.size() == nums.size())
            {
                ans.emplace_back(subset);
                return;
            }

            for (int i{}; i < nums.size(); i++)
            {
                // only add if not in set
                if (set.find(nums[i]) != set.end())
                {
                    continue;
                }

                subset.emplace_back(nums[i]);
                set.insert(nums[i]);
                backtracking();

                set.erase(nums[i]);
                subset.pop_back();
            }
        };

        backtracking();
        return ans;
    }
};
