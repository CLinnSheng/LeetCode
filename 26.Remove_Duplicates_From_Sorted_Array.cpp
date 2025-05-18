#include <set>
#include <unordered_set>
#include <vector>

/*
 * nums is sorted in ascending order, remove the duplicates in-place such that each unique element appear only once.
 * Relative order should be kept the same.
 * Consider the number of unique elements of nums are k:
 * i. Change the array nums such that the first k elements of nums contain the unique elements in the order they were
 * present in nums initially. Remaining elements of nums are not important as well as the size of nums. Goal: Return k.
 *
 * Eg: nums = [1,1,2]
 * Output: 2 & nums --> [1,2,_]
 *
 * Intuitoin:
 * The most straightaway approach is by using a set which kept the element in sorted manner
 * but this will take time complexity of O(nlgn)
 *
 * We can optimize it to O(n) by using 2 pointer.
 * 1 pointer will be the iterating one while the other 1 will be for the nxt index to be replaced
 * */
class Solution
{
  public:
    int removeDuplicates(std::vector<int> &nums)
    {
        // Time Complexity: O(nlgn)
        // std::set<int> elements;
        // for (int i{}; i < nums.size(); i++)
        //     elements.insert(nums[i]);
        //
        // nums.resize(elements.size());
        // int i{};
        // for (const int &element : elements)
        //     nums[i++] = element;
        //
        // return elements.size();

        // Time Complexity: O(n)
        std::unordered_set<int> elements;
        int ptr1{}, it{};
        for (; it < nums.size(); it++)
            if (elements.count(nums[it]) == 0)
            {
                nums[ptr1] = nums[it];
                ptr1++;
                elements.insert(nums[it]);
            }

        nums.resize(ptr1);
        return elements.size();
    }
};
