#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;

/*
 * Goal: Rotate the array to the right by k steps.
 *
 * Intuition:
 * Use an additional array to store the element with new index
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * How do we do it in O(1) space
 * Through the observation of rotating the array k times, we notice there are 2 groups of element in the array
 * THe last k element will be shift to the front & then rest of the element will be shift to the end.
 * We can achieve it by first reverse all the element. Then we will reverse the element from 0 until k - 1 in order to
 * follow the order Then the same for k until n -1 element eg: 1, 2, 3, 4, 5, 6, 7 -> 3 reversed: 7, 6, 5, 4, 3, 2, 1
 * (0, k - 1) 5, 6, 7, 4, 3, 2, 1
 * (k, n - 1) 5, 6, 7, 1, 2, 3, 4
 * */
class Solution
{
  private:
    void reverse(int left, int right, vector<int> &nums)
    {
        while (left < right)
        {
            std::swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

  public:
    void rotate(vector<int> &nums, int k)
    {
        int n(nums.size());
        if (n == k)
            return;

        k %= n;

        // // O(n) Space
        // // val -> index
        // std::vector<int> temp(n);
        // for (int i{}; i < n; i++)
        //     temp[(i + k) % n] = nums[i];
        //
        // for (int i{}; i < n; i++)
        //     nums[i] = temp[i];

        reverse(0, n - 1, nums);
        reverse(0, k - 1, nums);
        reverse(k, n - 1, nums);
    }
};
