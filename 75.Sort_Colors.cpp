#include <utility>
#include <vector>

/*
 * Given an array of integers colored red, white or blue. Sort them in-place so that objects of the same colors are
 * adjacent with the order of red, white & blue
 *
 * 0 - Red
 * 1 - White
 * 2 - Blue
 *
 * Intuition:
 * Use 3 pointer to keep track of the current index for each color
 * */
class Solution
{
  public:
    void sortColors(std::vector<int> &nums)
    {
        int n(nums.size());

        // all this pointer represent the index to place the responding color
        int red_entryIndex{}, white_entryIndex{}, blue_entryIndex{n - 1};

        // we only move the white_entryIndex pointer
        while (white_entryIndex <= blue_entryIndex)
        {
            if (nums[white_entryIndex] == 0)
                // move the red pointer
                std::swap(nums[red_entryIndex++], nums[white_entryIndex++]);
            else if (nums[white_entryIndex] == 1)
                white_entryIndex++;
            else
                // swap it with the blue and do not move the white pointer because we dont know the value at
                // nums[blue_entryIndex]
                std::swap(nums[white_entryIndex], nums[blue_entryIndex--]);
        }
    }
};
