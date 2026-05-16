class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        // Most direct way is find it using a hash set but this required O(n) space
        // How can we achieve it in O(1)?
        // Means that we cannot use any extra space or just a variable or existing space
        // Heres the hint --> Variable or existing space
        // Variable seems impossible in O(1) because we need to track every value information
        // So we only left with existing space
        // We can think of each number corresponds to an index since every number is in the range of [1, n]
        // For every index we iterate through we mark it dirty
        // If we encounter a dirty index means duplicate

        for (const auto num : nums)
        {
            int index = abs(num) - 1;

            // Check whether we encounter this index / number before
            if (nums[index] < 0)
            {
                return abs(num);
            }

            // Mark it dirty
            nums[index] *= -1;
        }
        return -1;
    }
};
