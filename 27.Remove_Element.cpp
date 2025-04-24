#include <vector>

/*
 * Given an integer array nums and an integer val, remove all occurences of val in nums in place.
 * Goal: Return the number of elements in nums which are not equal to val.
 *
 * Intuition:
 * When we remove we need to replace it with the next integer not equal to val.
 * How can we do that?
 * We can simply solve it with 2 pointers, while 1 pointer will keep finding element not equal to val
 * while another 1 pointing to the current place to store the num
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int index{};

        for (auto &num : nums)
            if (num != val)
                nums[index++] = num;

        return index;
    }
};
