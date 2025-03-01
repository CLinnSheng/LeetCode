#include <vector>
using std::vector;

/*
 * You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), you will apply the
following on the ith element of nums:

    If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.

After performing all the operations, shift all the 0's to the end of the array.
 *
 * Intuitoin:
 * We just need to run through the array if operations is done just add it into the answer array, no need to bother for
the 0's first
 * Then run through the array again to move all the 0's to the back
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    vector<int> applyOperations(vector<int> &nums)
    {

        for (int i{}; i < nums.size() - 1; i++)
            // if the val is 0, wont make much different because both are 0 already and 0 * 2 also 0
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }

        int notZeroIndex{};
        for (int i{}; i < nums.size(); i++)
            if (nums[i] != 0)
            {
                nums[notZeroIndex] = nums[i];
                notZeroIndex++;
            }

        while (notZeroIndex < nums.size())
            nums[notZeroIndex++] = 0;
        return nums;
    }
};
