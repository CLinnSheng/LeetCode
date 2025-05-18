#include <utility>
#include <vector>

/*
 * Goal: Rotate the array to the right by k steps where k is non negative
 *
 * IntuitioN:
 * The array is rotated to the right.
 * k can be any numbers of from [0, 100000]
 * So instead of looping k we can at most actually rotate the array by n - 1
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Can we optimize the space complexity? to O(1)??
 * So that means we cant use extra space. The most we can use is use variable
 * If we really go and observer how the rotate works, we will see there are 2 groups of element in the array
 * the left group will be move to the end and the right group will move to the front after k reverse
 * What we can do is reverse the 2 groups first then only reverse the internal group
 * eg: 1,2,3,4,5,6,7 & k = 3 The 2 groups will be 1,2,3,4 & 5,6,7
 * 1st reverse: 7,6,5,4,3,2,1
 * 2nd reverse: 5,6,7,4,3,2,1
 * 3rd reverse: 5,6,7,1,2,3,4
 * */
class Solution
{
  private:
    void reverse(std::vector<int> &nums, int left, int right)
    {
        while (left < right)
        {
            std::swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

  public:
    void rotate(std::vector<int> &nums, int k)
    {
        int n(nums.size());
        // finding out the true k
        k %= n;

        // Approach 1: Space Complexity of O(n)
        // std::vector<int> temp(nums.begin(), nums.end());
        //
        // for (int i{}; i < n; i++)
        //     temp[(i + k) % n] = nums[i];
        //
        // for (int i{}; i < n; i++)
        //     nums[i] = temp[i];

        // Approach 2: Space Complexity: O(1)
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};
