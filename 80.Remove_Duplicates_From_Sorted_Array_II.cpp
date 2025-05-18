#include <map>
#include <vector>

/*
 * Nums is sorted in ascending order.
 * Remove duplicates in-place such that each unique element appears at most twice & relative order should be kept the
 * same. Have the result be placed in the first part of the array nums.
 *
 * Goal: Return k after placing the final result in the first k slots of nums.
 *
 * Intuition:
 * Each unique element can be appear at most twice.
 * The first data appear comes into mind is by using a hash map. (Specifically map because we needed to retrieve it in a
 * sorted manner) Then only use those that have appear at most twice Time Complexity: O(nlgn)
 *
 * */
class Solution
{
  public:
    int removeDuplicates(std::vector<int> &nums)
    {
        std::map<int, int> map;
        for (const auto &num : nums)
            map[num]++;

        int it{};
        int k{};
        for (const auto &[val, freq] : map)
        {
            int f{freq > 2 ? 2 : freq};
            k += f;

            while (f)
            {
                nums[it] = val;
                it++;
                f--;
            }
        }

        nums.resize(it);
        return k;
    }
};
