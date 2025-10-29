#include <vector>
/*
 * Start a position such that its value is 0. Choose a movement of either left or right.
 * Process:
 * 1. If out of range then end
 * 2. If values is 0 then move in the current direction by incrementing curr if moving right otherwise decremnting
 * 3. If > 0
 *      Decrement  nums[curr] by 1
 *      Reverse movement direction
 *      Take a step in new direction
 *
 * Goal: Return the number of possible valid selections
 *
 * Intuition:
 * Just stimulate the process
 */
class Solution
{
  public:
    int countValidSelection(std::vector<int> &nums)
    {
        int cnt{};
        std::vector<int> zeros;
        for (const auto &i : nums)
        {
            if (i == 0)
                zeros.push_back(i);
        }

        for (const auto &i : zeros)
        {
            int position{i};
            std::vector<int> temp(nums);
            // Left
            position++;
            while (i >= 0 && i < nums.size())
            {
            }
        }

        return cnt;
    }
};
