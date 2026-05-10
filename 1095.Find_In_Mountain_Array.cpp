/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
  public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        // Brute force will just simply linear scan O(n)
        // So how can we optimize it further? Possible is just O(1) or O(lgn)
        // O(1) seems impossible so we will look into O(lgn)
        // O(lgn) will be simply binary search
        // So how do we apply binary search in this context
        // Binary search always needed a sorted array but in this context the arrays are not sorted
        // Key Observations is the array is split into 2 parts
        // First part will be ascending and second part will be descending order
        // So we need to find the peak first
        int left{}, right{mountainArr.length() - 1};

        while (left < right)
        {
            int middle = left + (right - left) / 2;

            // Checking is it a valid peak or not
            if (mountainArr.get(middle) > mountainArr.get(middle + 1))
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }

        int peak = left;

        // Binary saerch in both part
        // Ascending Order
        left = 0;
        right = peak;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            int val = mountainArr.get(middle);

            // Checking is it a valid peak or not
            if (val == target)
            {
                return middle;
            }
            else if (val > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        // Descending Order
        left = peak;
        right = mountainArr.length() - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            int val = mountainArr.get(middle);

            // Checking is it a valid peak or not
            if (val == target)
            {
                return middle;
            }
            else if (val > target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        return -1;
    }
};
