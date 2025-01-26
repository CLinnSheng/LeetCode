#include <algorithm>
#include <vector>
using std::vector;

/*
 * Return an array of all the unqiue quadruplets where nums[a] + .. nums[d] such that 0 <= a, b, c, d n
 * and they all are distinct
 * sum of nums[a]+..+nums[d] == target
 * In any order
 * Constraint: Unique combination
 *
 * Intuition:
 * First we sort it first, so that we can easily determine that whether should we continue to search for it ornot
 * because the element can be negative or positive, so whenever if the curr element already greater or equal to target
 * there is no reason to continue
 *
 * And then we can fix 1 element to find the other 3 element. Which is the same as how we solve 3 sum.
 * Now we will be implementing 3 sum for the other 3 element
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 * */
class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n(nums.size());
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> answer;

        // O(n)
        for (int i{}; i < n; i++)
        {
            // to prevent duplicate quadruplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // O(n)
            for (int j{i + 1}; j < n; j++)
            {
                // prevent duplicate quadruplets
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // now we have lock both i & j, we just need to find the other 2
                int left{j + 1}, right{n - 1};
                // O(n)
                while (left < right)
                {
                    long long sum{static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right]};

                    if (sum > target)
                        right--;
                    else if (sum < target)
                        left++;
                    else
                    {
                        answer.push_back({nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        right--;

                        // need to try all possibilities with the combination of i & j
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }

        return answer;
    }
};
