#include <unordered_map>
#include <vector>

/*
 * Given an array nums of size, return the majority element
 * Majority element is the element that appears more than n / 2 times.
 *
 * Intuition:
 * Just use hash data structure to keep track of the count
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Can we do it in O(1) of space complexity?
 * Just 2 variable to keep track of the freq & the current most element
 * */
class Solution
{
  public:
    int majorityElement(std::vector<int> &nums)
    {
        int n(nums.size());
        // std::unordered_map<int, int> freq_count;
        //
        // for (const auto &num : nums)
        //     freq_count[num]++;
        //
        // for (const auto &[val, freq] : freq_count)
        //     if (freq >= n / 2.0)
        //         return val;
        //
        // return -1;

        // > 0 is 1 or < 0 is 0
        int freq{}, currentMostElement{};
        for (const auto &num : nums)
        {
            // when equal to zero switch to new element
            if (freq == 0)
                currentMostElement = num;

            freq += currentMostElement == num ? 1 : -1;
        }
        return currentMostElement;
    }
};
