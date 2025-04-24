#include <unordered_map>
#include <unordered_set>
#include <vector>
/*
 * Goal: Return the number of complete subarrays
 * Complete Subarray: Number of distinct elements in the subarray is equal to the number of distinct element in the
 * whole array
 *
 * Intuition:
 * We need a hash set to keep track the number of distinct element in the array
 * But how do find out the subbarray?
 * The naive way will just simply loop through the array twice to check every single possible subarray.
 * But this is inefficient O(n^2)
 *
 * Can we further optimize it? reduce the number of loop?
 * is either to O(nlgn)/O(n)/O(lgn)
 * to linear time is more pratical if need to nlgn or n it will involve binary search
 * Since we are not finding a particular things within a certain range, so the linear time will be the only option
 * If we observe from the brute force attempt, we will observe that we actually see there're overlapping subarray.
 * We can use sliding window algo
 * Another key observation is that the minimum size of subarray will be the number of distinct elment
 * So if the current window is already statisfied, then the number of subarray count will simply be the size - the right
 * pointer, because any element behind it adding to the subarray will also be complete because will be repeating
 * elements O(n)
 * */
class Solution
{
  public:
    int countCompleteSubarrays(std::vector<int> &nums)
    {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int distinct_element(set.size());

        int left{}, right{};
        int cnt{};

        std::unordered_map<int, int> currSet;

        while (right < nums.size())
        {

            currSet[nums[right]]++;

            while (left <= right && currSet.size() == distinct_element)
            {
                cnt += nums.size() - right;
                currSet[nums[left]]--;

                if (currSet[nums[left]] == 0)
                    currSet.erase(nums[left]);

                left++;
            }

            right++;
        }

        return cnt;
    }
};
