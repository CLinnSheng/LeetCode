#include <vector>
using std::vector;

/*
 * Given 2 array sorted in ascending order, and 2 integers representing the number of elements in nums1 and nums
 * respectively. Merge nums1 and nums2 into a single array sorted in ascending order. Final array should not be returned
 * by the function, but instead be stored inside the array nums1.
 *
 * Intuition:
 * Each array having 1 pointer point to the current element. So just compare the element of the pointer from each array
 * and decide who to put next. 1 easiery way is to compare from the back since the array is already sorted, can save a
 * little bit computational time if nums2 run out first, so the rest is from nums1 we dont have to continue to insert it
 * already.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int pointer_1{m - 1}, pointer_2{n - 1};

        while (pointer_1 >= 0 && pointer_2 >= 0)
        {
            if (nums1[pointer_1] >= nums2[pointer_2])
            {
                nums1[pointer_1 + pointer_2 + 1] = nums1[pointer_1];
                pointer_1--;
            }
            else
            {
                nums1[pointer_1 + pointer_2 + 1] = nums2[pointer_2];
                pointer_2--;
            }
        }

        // check whether is there any element left from nums2
        while (pointer_2 >= 0)
        {
            nums1[pointer_2] = nums2[pointer_2];
            pointer_2--;
        }
    }
};
