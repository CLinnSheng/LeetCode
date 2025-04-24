#include <vector>
using std::vector;

/*
 * Goal: Sort the array in ascending order
 * Constraint: Cannot use any built in sorting algorithm
 *
 * Intuition:
 * Just apply merge sort where at worst case only O(nlgn)
 * Selection Sort also can
 * */
class Solution
{
  public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int> &nums, int start, int end)
    {
        // base case only left 1 element
        if (start >= end)
            return;

        // divide & conquer strategy
        // keep divide until size of 1 and built it up from that
        int mid(start + (end - start) / 2);

        // divide
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

        // merging the 2 sorted array
        merge(nums, start, end);
    }

    void merge(vector<int> &nums, int start, int end)
    {
        // perform insertion sort
        int mid(start + (end - start) / 2);
        int i{start}, j{mid + 1};
        std::vector<int> temp;

        while (i <= mid && j <= end)
        {
            if (nums[i] >= nums[j])
                temp.emplace_back(nums[j++]);
            else
                temp.emplace_back(nums[i++]);
        }

        // Insert the remaining array
        while (i <= mid)
            temp.emplace_back(nums[i++]);

        while (j <= end)
            temp.emplace_back(nums[j++]);

        // update on the reference array
        for (int index{start}; index <= end; index++)
            nums[index] = temp[index - start];
    }
};
