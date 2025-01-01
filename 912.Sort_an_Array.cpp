#include <vector>
using std::vector;

/*
 * Goal: Sort the array in ascending order
 * Constraint: Cannot use any built in sorting algorithm
 *
 * Intuition:
 * Just apply merge sort where at worst case only O(nlgn)
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
        // divide and conquer until left 1 element only, so straight away return
        if (start >= end)
            return;

        int mid{start + (end - start) / 2};

        // Divide and Conquer
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        // Then merge the 2 half half sorted array
        merge(nums, start, end);
    }

    void merge(vector<int> &nums, int start, int end)
    {
        int mid{start + (end - start) / 2};
        int i{start}, j{mid + 1};
        vector<int> temp;

        while (i <= mid && j <= end)
            if (nums[i] <= nums[j])
                temp.emplace_back(nums[i++]);
            else
                temp.emplace_back(nums[j++]);

        while (i <= mid)
            temp.emplace_back(nums[i++]);

        while (j <= end)
            temp.emplace_back(nums[j++]);

        for (int i{start}; i <= end; i++)
            nums[i] = temp[i - start];
    }
};
