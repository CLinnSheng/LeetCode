#include <unordered_set>
#include <vector>

/*
 * An integer h is valid if all values in the array that are strictly greater than h are identical
 * eg: nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid
 * integer So we can perform the operations of all nums[i] > valid integer:
 * - Select an integer h is that valid for the current values n nums
 * - For each index i where nums[i] > valid integer(h), set nums[i] to h
 *
 * Goal: Return the minimum number of operations are required to make every element in nums equal to k. otherwise return
 * -1
 *
 *
 * Intuiton:
 * One key important observation is if there exists a number in nums that is smaller than k then it is impossible
 * to change the number equal to k. Because the valid integer we choosing must be smaller than the curent index element,
 * and after the operation the value will only get smaller
 * Since the operations can only apply to the nums[i] where is it greater than h and also have the identical value
 * So, the number of operations is actually we need to find out the number of distinct element that is greater k in the
 * array
 * We dont really need to know what the h value for the operation.
 * But obviously it will go down to the next element which is smaller than him, so we can reduce the number of
 * operations
 * So we can use a hash set to keep track of the number of unique elements
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int minOperations(std::vector<int> &nums, int k)
    {
        std::unordered_set<int> set;

        for (const auto &num : nums)
        {
            if (num < k)
                return -1;
            // only insert those greater k, because we not going to do any operatoin on value already equal to k
            if (num > k)
                set.insert(num);
        }
        return set.size();
    };
};
