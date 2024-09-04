#include <climits>
#include <ios>
#include <iostream>
#include <vector>

/*
Goal: Find the median of two sorted arrays after combining
Intuition: Using the naive way is merge the two sorted array and then sort it -> find the median ---> This will result time complexity in (Onlgn)

Intuition: Since both arrays are sorted we just need to find the first part of the merged array by doing binary search on both array
1. Take half of the array from ArrayA(smaller)
2. Then tke the remaining from ArrayB(half - size of half(ArrayA))
3. Then make sure the leftA <= rightB && leftB <= rightA to ensure it is a corrected sorted merge array for the first half
4. If wrong, we will reduce either from arrayA or arrayB through determining whether is it leftA > rightB or leftB > rightA

Time Complexity: O(lgm + lgn)
*/

class Solution 
{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int size1 = nums1.size(), size2 = nums2.size();
        int half = (size1 + size2 + 1) / 2;
        
        int left = 0, right = size1;
        
        while (left <= right)
        {
            int i = (left + right) / 2; // Size of Left partition in arrayA
            int j = half - i; // Size of Left partition in arrayB
            
            int Left_A = i > 0? nums1[i - 1] : INT_MIN;
            int Right_A = i < size1? nums1[i] : INT_MAX;
            int Left_B = j > 0? nums2[j - 1] : INT_MIN;
            int Right_B = j < size2? nums2[j] : INT_MAX;
            
            if (Left_A <= Right_B && Left_B <= Right_A)
            {    
                if ((size1  + size2) % 2) // Odd
                    return std::max(Left_A, Left_B);
                else
                    return (std::max(Left_A, Left_B) + std::min(Right_A, Right_B)) / static_cast<double>(2);
            }
            
            // we have to shrink the partition at A
            if (Left_A > Right_B)
                right = i - 1;
            else
                left = i + 1;
        }
        
        return -1;
    }
};