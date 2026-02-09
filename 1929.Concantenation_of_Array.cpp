#include <vector>

/*
 * Goal: Return concatenation of the 2 arrays
 *
 * Intuition:
 * Just simply create an array of 2*n and then ans[n + i] = ans[i]
 * */
class Solution
{
  public:
    std::vector<int> getConcatenation(std::vector<int> &nums)
    {
        int len(nums.size());
        for (int i{}; i < len; i++)
            nums.emplace_back(nums[i]);
        return nums;
    }
};
