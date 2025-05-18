#include <vector>

/*
 * Given an array of integers sorted in acending order
 * Goal: Return the indices of 2 numbers such that they add up to a given target number target and index1 < index2.
 * Take NOTE: Always be exactly one valid solution
 *
 * Intuition:
 * important thing is the numbers is sorted and there's always exist 1 solution
 * another thing is cannot use the same element twice
 * The brute force will just simply trying all possible pair but this will cost O(n^2)
 *
 * Can we make use of the sorted array?
 * We can use 2 pointer 1 pointing at the beginning and another at the end.
 * So we will simply move the left pointer if the sum is too less and move the right if the sum is too big
 * */
class Solution
{
  public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target)
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
