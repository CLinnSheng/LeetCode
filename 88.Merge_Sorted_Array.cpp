#include <vector>
using std::vector;

/*
 * Given 2 arrays and both are sorted in ascending order.
 * m is the number of valid elements in nums1, n is the number of valid elements in nums2.
 * array nums1 has a total length of m + n with the first m elements containing the values to be merged and the last n
 * elements set to 0 as place holders.
 *
 * Goal: Merge thw two arrays such that the final array is sorted within nums1.
 *
 * Intuition:
 * Both arrays are sorted in ascending order.
 * Must modify nums1 inplace & not returning anything from the function.
 * Since both array are sorted, is better to compare from the end because if the are not sorted in the correct order we
 * have to move everything to the right. Time Complexity: O(m + n) Space Complexity: O(1)
 * */
class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int ptr1{m - 1}, ptr2{n - 1};
        int last{m + n - 1};

        while (ptr1 >= 0 && ptr2 >= 0)
        {
            if (nums1[ptr1] >= nums2[ptr2])
            {
                nums1[last] = nums1[ptr1];
                ptr1--;
            }
            else
            {
                nums1[last] = nums2[ptr2];
                ptr2--;
            }
            last--;
        }

        // Edge cases if nums2 are not merged all
        while (ptr2 >= 0)
        {
            nums1[last] = nums2[ptr2];
            last--;
            ptr2--;
        }
    }
};
