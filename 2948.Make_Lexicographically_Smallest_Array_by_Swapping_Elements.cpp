#include <algorithm>
#include <cstdlib>
#include <deque>
#include <unordered_map>
#include <vector>

/*
 * Operation: Choose any 2 indices i & j and swap nums[i] & nums[j] if abs(nums[i] - nums[j]) <= limit
 * Goal: Return the lexicographically smallest array that can be obtained by performing the operation at any number of
 * time
 *
 * An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an
 * element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically
 * smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.
 *
 * Intuition:
 * We can only swap 2 number if their abs diff is equal or lesser than the limit
 * eg: if [4, 3, 2, 1] can be sorted into [1, 2, 3, 4] with limit 1 because all the abs diff between adj elements is
 * within the limit. how about [7, 6, 1, 3, 2, 4] can be sorted into [6, 7, 1, 2, 3, 4] if we notice theres actually 2
 * group of elements with adj elements of abs diff of 1. What we need to do is first sort the array and then find out
 * the number of group of element and assign the element into their respective group. So what we basically need to do is
 * just sort each group.
 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(nlgn)
 * */
class Solution
{
  public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int> &nums, int limit)
    {
        std::vector<int> copy(nums);
        // O(nlgn)
        std::sort(copy.begin(), copy.end());

        // to store the group of element with the abs diff within the limit
        std::vector<std::deque<int>> groups;
        // to store which group does the elemnt belongs to
        std::unordered_map<int, int> groupIndex;

        // O(n)
        for (int i{}; i < copy.size(); i++)
        {
            // if out of the group, append to the new group
            if (groups.empty() || std::abs(groups[groups.size() - 1].back() - copy[i]) > limit)
                groups.emplace_back(std::deque<int>());

            groups[groups.size() - 1].emplace_back(copy[i]);
            groupIndex[copy[i]] = groups.size() - 1;
        }

        std::vector<int> answer;
        // O(n)
        for (const auto &num : nums)
        {
            answer.emplace_back(groups[groupIndex[num]].front());
            groups[groupIndex[num]].pop_front();
        }

        return answer;
    }
};
