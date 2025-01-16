#include <vector>
using std::vector;

/*
 * Given 2 0-indexed array consisting of non-negative integers only. There exists another array,
 * nums3 which contains the bitwise XOR of all pairing of integers between nums1 & nums2
 * (every integer in nums1 is paired with every integer in nums2 exactly once)
 *
 * Goal: Return the bitwise XOR of all integers in nums3
 *
 * Intuition:
 * The brute force way is to compute every single pair of XOR values & store it in a array.
 * Then iterate through the array again.
 * Time Complexity: O(n^2)
 *
 * How can we optimize it to linear time?
 * XOR operations property: A ^ B ^ A -> A
 * If we notice from all the XOR operations from the brute force way.
 * We might see theres a lot of character repeated a certain times. So we can make use of this A ^ B ^ A things
 * Therefore, we need to find out the number of times each character appear from each array.
 * if nums1 length is m & nums2 is n
 * then elements from nums1 will repeated n time & for nums2 will be m
 * So if the freq is even they eventually will cancel out each other, so only go for the array with odd
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * */
class Solution
{
  public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int answer{};
        int size1(nums1.size()), size2(nums2.size());
        // nums1 appear size2 time & nums2 appera size1 time

        if (size1 % 2)
            for (const auto &num : nums2)
                answer ^= num;

        if (size2 % 2)
            for (const auto &num : nums1)
                answer ^= num;

        return answer;
    }
};
