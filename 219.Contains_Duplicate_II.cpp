#include <cstdlib>
#include <unordered_map>
#include <vector>
using std::vector;

/*
 * Goal: Return true if there are 2 distinct indices i & j such that nums[i] == nums[j] and abs(i - j) <= k
 *
 * Intuition:
 * The first come to mind is using sliding window because we try to find within a specific range then need to keep
 * shifting it Just keep moving the right pointer until more than k than only move the left pointer
 * But there's a little bit complicated to code it out
 *
 * The best way is we try to cache the index of every single element, so we can just access it in O(1) for the index of
 * element we want
 * We can use hash data structure
 * */
class Solution
{
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int size(nums.size());
        if (size == 1)
            return false;

        std::unordered_map<int, int> hashIndex;
        for (int i{}; i < size; i++)
        {
            if (hashIndex.count(nums[i]))
                if (std::abs(i - hashIndex[nums[i]]) <= k)
                    return true;
            hashIndex[nums[i]] = i;
        }
        return false;
    }
};
