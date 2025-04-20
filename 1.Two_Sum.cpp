#include <unordered_map>
#include <vector>

/*
 * Goal: Return indices of the two numbers such that they add up to target
 * Assume each input would have exactly one solution, may not use the same element twice
 *
 * Intuition:
 * The brute force will just simply loop through the array for every index
 * But this will result in time complexity: O(n^2)
 *
 * Observation:
 * From the brute force, we can see we need information from the future. But we cant accessed right
 * The only information we can access is actually from the past.
 * How about we make use of it?
 * So we will just store whatever element we traversed in a hash map because we need to index, then while iterate
 * through the array just find whether there exists nums[i] - target? Time Complexity: O(n)
 * */
class Solution
{
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {

        // 1. Brute force
        // for (int i{}; i < nums.size(); i++)
        //     for (int j{i + 1}; j < nums.size(); j++)
        //         if (nums[i] + nums[j] == target)
        //           return {i, j};

        // 2. Optimized
        std::unordered_map<int, int> ele_index;
        for (int index{}; index < nums.size(); index++)
            if (ele_index.count(target - nums[index]))
                return {ele_index[target - nums[index]], index};
            else
                ele_index[nums[index]] = index;

        return {};
    }
};
