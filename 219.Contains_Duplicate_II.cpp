#include <unordered_map>
#include <vector>
/*
 * Goal: Return true if there are 2 distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <=
 * k
 *
 * Intuition:
 * The information we need is the value and its index
 * So we can make use hash map
 * */

class Solution
{
  public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> map;

        for (int i{}; i < nums.size(); i++)
            if (map.count(nums[i]) && i - map[nums[i]] <= k)
                return true;
            else
                map[nums[i]] = i;
        return false;
    }
};
