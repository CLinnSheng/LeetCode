#include <algorithm>
#include <climits>
#include <unordered_set>
#include <vector>

/*
 * Given an integer array nums. Need to ensure that the elements in the array distinct. To achieve this can perform this
 * operation any number of times
 * - Remove 3 elements from the beginning of the array. If the array has less than 3, remove all the remaining.
 *
 * Goal: Find the minimum number of operations to mkae the element in the array are ditinct.
 *
 * Intuition:
 * So, it mentioned about the elements in the array must be distinct --> The first data structure comes into mind is
 * using a hash set The way to check is very simple, compare the size of array and also the size of the hash set. When
 * the elements are unique they should share the same size.
 *
 * Time Complexity: At worst will be looping n times if all n element are the same and also updating the hsah set will
 * be O(n) as well So in result O(n^2)
 *
 * How can improve this to nlgn? n? lgn?
 * One important observation is there is a search space over here is simply [0, (nums.size() + 2)/3]
 * So we can do binary search on this search space
 * Try to see with the number of operations whether can we make it unique or not
 * the checking process is exactly the same as the brute force but we just shrink the number of search through binary
 * search Time Complexity: O(nlgn)
 *
 * Can we further optimize it to O(n)? Actually we can
 * There is one key important observation is the removal always happen at the front, so the unqiue element that are left
 * are from the back So we can actually work in the back, iterate through until we find a duplicated elements, from
 * there we can tell how many number of operations that we need
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int minimumOperations(std::vector<int> &nums)
    {
        // 1. Approach 1 (Brute Force)
        // std::unordered_set<int> set(nums.begin(), nums.end());
        // int nOperations{};
        //
        // // O(N)
        // while (nums.size() != set.size())
        // {
        //     // do the operation
        //     nOperations++;
        //
        //     // just in case smaller than 3
        //     int eraseSize{std::min(3, int(nums.size()))};
        //     nums.erase(nums.begin(), nums.begin() + eraseSize);
        //
        //     // O(N)
        //     set = std::unordered_set<int>(nums.begin(), nums.end());
        // }
        // return nOperations;

        // 2. Binary Search
        // int left{}, right{int(nums.size() + 2) / 3};
        // int nOperations{INT_MAX};
        //
        // // O(lgn)
        // while (left <= right)
        // {
        //     int mid{left + (right - left) / 2};
        //
        //     std::vector<int> temp;
        //
        //     // see whether with this number of operations, do we still have any element left
        //     // upper bounded by O(n)
        //     if (mid * 3 < nums.size())
        //     {
        //         for (auto it = nums.begin() + mid * 3; it != nums.end(); it++)
        //             temp.emplace_back(*it);
        //     }
        //
        //     // O(n)
        //     std::unordered_set<int> set(temp.begin(), temp.end());
        //
        //     if (set.size() != temp.size())
        //     {
        //         left = mid + 1;
        //     }
        //     else
        //     {
        //         right = mid - 1;
        //         nOperations = std::min(nOperations, mid);
        //     }
        // }
        // return nOperations;

        // 3. Linear (From the back)
        int maxOperations((nums.size() + 2) / 3);
        std::unordered_set<int> set;

        for (int i{}; i < maxOperations; i++)
        {
            // we need to make sure the offset is correct
            // not removing from behind but from the front
            // this offset tell us the index that should start at if we apply maxOperations - i
            int offSet{(maxOperations - i - 1) * 3};

            for (int j{}; j < 3; j++)
            {
                if (offSet + j < nums.size())
                {
                    if (set.count(nums[offSet + j]))
                        return maxOperations - i;
                    else
                        set.insert(nums[offSet + j]);
                }
                else
                    break;
            }
        }
        return 0;
    }
};
