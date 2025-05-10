#include <vector>
using std::vector;

/*
 * Numbers is sorted in non-decreasing order --> ascending order
 * Goal: Find 2 number such that they add up to a specific target number
 *
 * Goal: Return the indices of the 2 numbers, index1 and index2 added by one as an integer array [index1,index2] of
 * length2
 *
 * Intuition:
 * The brute force way is just simply loop through the array twice to try all possible pair
 *
 * How can we optimize this?
 * Since the array is sorted --> how can we make use of this information?
 * And we only need 2 pair, --> 2 pointer each pointed to the maybe "pair of values"
 * If the sum is too large we need to move the right pointer because it gonna be larget if we move the left pointer.
 * And we need to move the left because need to decrease the total sum, same for the left pointer.
 * if too small need to move to the right to increase the sum.
 * IMPORTANT: There always exists a solution
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * */

class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left{}, right(numbers.size() - 1);

        while (left < right)
        {
            int sum{numbers[left] + numbers[right]};

            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else
                return {left + 1, right + 1};
        }
        return {-1, -1};
    }
};
