#include <vector>

/*
 * Given an array nums, return true if the array was originally sorted in ascending order, then rotated some number of
 * positions. otherwise return false Note: Might have duplicate elements in the array. eg: 3, 4, 5, 1, 2 this is a
 * sorted and rotated array -> 1, 2, 3, 4, 5
 *
 * Intuition:
 * The naive way will be checking the array by using a double loop
 * Time Complexity: O(n^2)
 *
 * Cna we make it in linear time? Yes
 * if we observe this is a rotated array, so we just need to append the original array to the back of the array.
 * 3, 4, 5, 1, 2 -> 3, 4, 5, 1, 2, 3 ,4 ,5, 1, 2
 * And then we dont really have to keep checking in N window.
 * We just need to find the least element first and then continue until the window size is N.
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    bool check(std::vector<int> &nums)
    {
        int n(nums.size());
        if (n == 1)
            return true;

        int cnt{1};
        for (int i{1}; i < 2 * n; i++)
        {
            if (nums[i % n] >= nums[(i - 1) % n])
                cnt++;
            else
                // continue searching the least element
                cnt = 1;

            if (cnt == n)
                return true;
        }
        return false;
    }
};
