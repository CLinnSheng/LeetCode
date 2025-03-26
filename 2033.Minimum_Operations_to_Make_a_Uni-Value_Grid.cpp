#include <algorithm>
#include <climits>
#include <vector>

/*
 * Operation: add or subract x from any element in the grid. Only 1 element in 1 time
 * Goal: Return the minimum number of operations to make the gridwhere all elements are equal
 *
 * Intuition:
 * First is it always possible to make all the element equal for any random value by adding or subtracting x.
 * Odd - Even => Odd
 * Even - Even => Even
 * So we can use modolus to check whether they all can ahieve the same value by adding or subtracting
 *
 * Then how do we check the number of operation to reach the same value?
 * The brute force is just to check each value with all other value the number of iteration to reach the value and sum
 * it up. Then take the minimum
 * But this will take O(n^2)
 *
 * Can we further to optimize it? Can we just run through the array only once?
 * We can sort the array first, so the num is in order.
 * so for every index, we have to know the number of operation for the value before the index need to reach the value of
 * the index and also the number of operations needed for the value after the index as well.
 *
 * the total number of operation to reach an index for the value before the index is actually just the "expected" sum -
 * the current and then divide by x. Because we now counting the number of operation to have all the value equal to the
 * current index right, so it should have index * nums[index] so we want to know the differene in order to know how many
 * times of x we need to add which is the operation. The same goes to the value after the index
 * NOTE: We dont really need to know about adding the x to which value
 *
 * Time Complexity: O(mnlg(mn))
 * */
class Solution
{
  public:
    int minOperations(std::vector<std::vector<int>> &grid, int x)
    {
        int answer{INT_MAX};
        std::vector<int> nums;
        int ttlSum{};

        // 1. Check whether they all can achieve the same value or not
        for (int i{}; i < grid.size(); i++)
            for (int j{}; j < grid[0].size(); j++)
            {
                if (grid[i][j] % x != grid[0][0] % x)
                    return -1;
                else
                {
                    nums.emplace_back(grid[i][j]);
                    ttlSum += grid[i][j];
                }
            }

        // 2. Finding the minimum operatoin
        std::sort(nums.begin(), nums.end());
        int size(nums.size());
        int prevSum{};

        for (int index{}; index < size; index++)
        {
            int cost_left{nums[index] * index - prevSum};
            int cost_right{ttlSum - prevSum - (nums[index] * (size - index))};

            answer = std::min(answer, (cost_left + cost_right) / x);
            prevSum += nums[index];
        }

        return answer;
    }
};
