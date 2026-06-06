#include <functional>
#include <set>
#include <unordered_set>
#include <vector>

/*
 * Get all the possible unqiue permutations of nums
 * So need to handle duplicate elements in nums in order not to prodcue duplciate permutation
 * So at every index is either choose or not choose --> Backtracking to find all possible permutations
 * Time Complexity: O(n! * n) where n is the opetaion for each permutation
 * Inserting invovle copying all the elmeent from the vector & also hashing
 * Space Complexity: O(n! * n) n! permutations * n elmeents
 * */

class Solution
{
  public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
    {
        std::set<std::vector<int>> ans;
        std::vector<int> subset;
        std::unordered_set<int> set; // Storing the index

        std::function<void()> backtracking = [&]() {
            if (subset.size() == nums.size())
            {
                ans.insert(subset);
                return;
            }

            // O(n)
            for (int i{}; i < nums.size(); i++)
            {
                if (set.find(i) != set.end())
                {
                    continue;
                }

                set.insert(i);
                subset.emplace_back(nums[i]);

                backtracking();
                subset.pop_back();
                set.erase(i);
            }
        };

        backtracking();
        return std::vector<std::vector<int>>(ans.begin(), ans.end());
    }
};
