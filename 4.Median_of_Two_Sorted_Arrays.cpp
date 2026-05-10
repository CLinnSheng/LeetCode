#include <algorithm>
#include <climits>
#include <vector>
class Solution
{
  public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        //  Return the median value among all elements of the two arrays
        //  brute force will just simply store both the arrays into 1 single arrays and sorted it to find the median
        //  but this will O(m+n + mnlogmn)
        //
        //  But  we need to make it in O(lgmn)
        //  So that means we need to do binary search in both array

        // So the problem is how do we split the merged array into half without merging it?
        // We need to identify the elements from both arrays that belong to the left part
        int size1 = nums1.size(), size2 = nums2.size();

        // IMPORTANT: We always want to search in thee shorter array such taht
        // i & j is always valid adn never go out of scope
        if (size1 > size2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int half = (size1 + size2 + 1) / 2;
        int left{}, right{size1};

        while (left <= right)
        {
            // Position part at array1
            int i = (left + right) / 2;
            // Position part at array2
            int j = half - i;

            // Boundary Values
            int left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            int left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right1 = (i < size1) ? nums1[i] : INT_MAX;
            int right2 = (j < size2) ? nums2[j] : INT_MAX;

            // Checking Boundaries
            if (left1 <= right2 && left2 <= right1)
            {
                // Odd Numbers
                if ((size1 + size2) % 2)
                {
                    return std::max(left1, left2);
                }

                return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
            }
            else
            {
                if (left1 > right2)
                {
                    // Having too much element in array1
                    // Move it to the left (array1)
                    right = i - 1;
                }
                else
                {
                    // Having too much element in array2
                    // Move it to the right (array2)
                    left = i + 1;
                }
            }
        }
        return -1;
    }
};
