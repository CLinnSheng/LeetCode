#include <map>
#include <vector>
using std::vector;

/*
 * nums1[i] = [idi, vali] indicate the number with the idi has a value equal to vali.
 * Same goes to nums2
 * Merge the 2 arrays into one array that is sorted in ascending order by id.
 *
 * Intuition:
 * we can use a hash map to store the id and the value
 * Time Complexity: O(nlgn)
 *
 * We can improve this to O(n) by just using 2 pointers.
 * Sum up if those have equals id.
 * Push the smaller id into it first
 * */
class Solution
{
  public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        // std::map<int, int> map;
        // for (const auto &num : nums1)
        //     map[num[0]] += num[1];
        // for (const auto &num : nums2)
        //     map[num[0]] += num[1];
        //
        // vector<vector<int>> answer;
        // for (const auto &[key, val] : map)
        //     answer.push_back({key, val});
        //
        // return answer;

        vector<vector<int>> answer;
        int size1(nums1.size()), size2(nums2.size());
        int ptr1{}, ptr2{};

        while (ptr1 < size1 && ptr2 < size2)
        {
            if (nums1[ptr1][0] == nums2[ptr2][0])
            {
                answer.push_back({nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]});
                ptr1++;
                ptr2++;
            }
            else if (nums1[ptr1][0] > nums2[ptr2][0])
            {
                answer.push_back(nums2[ptr2]);
                ptr2++;
            }
            else
            {
                answer.push_back(nums1[ptr1]);
                ptr1++;
            }
        }

        while (ptr1 < size1)
            answer.push_back(nums1[ptr1++]);
        while (ptr2 < size2)
            answer.push_back(nums2[ptr2++]);

        return answer;
    }
};
