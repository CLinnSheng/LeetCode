#include <algorithm>
#include <unordered_set>
#include <vector>

/*
 * Given an unsorted array
 * Goal: Return the length of the longest consecutive element sequence.
 * Eg: [100, 4, 200, 1, 3, 2]
 * longest consecutive element will be [1, 2, 3, 4]
 *
 * Intuition:
 * Key important observation from the example is we dont have to follow the order of original element.
 * We just need to find all the possible consecutive element sequence.
 * So we need to know about the information of all the elements available in the array.
 * We can store it in a set. Then brute force it by trying from all the possible elements in the array. -1e9 <= nums[i]
 * <= 1e9. But this is super inefficient. Is there any way to optimize this? Yes instead of trying all possible integer,
 * why dont we just try all possible integer in the array only? How can we do this inefficiently? We can sort the array
 * first and then check whether is this elmeent the first element of a sequence in the array or not
 * we also need to take care of the same element in the array, so we simply just skip it
 * Time Complexity:
 * O(nlgn)
 * */
class Solution
{
  public:
    int longestConsecutive(std::vector<int> &nums)
    {
        // Most straight forward approach is just sort the array. Then have a pointer to go through the array and find
        // the longest sequence
        // Another more clever aprpaoch is actually just finding the starting point of the sequence. Which we can use a
        // hash set to store it

        std::unordered_set<int> set(nums.begin(), nums.end());
        int answer{};
        if (set.empty())
            return answer;

        for (auto num : nums)
        {
            // Check whether is this the first element or not
            if (set.count(num - 1))
            {
                continue;
            }

            // Once find the first element then find its length
            int len{1};
            while (set.count(num + 1))
            {
                len++;
                num++;
            }

            answer = std::max(answer, len);
        }
        return answer;
    }
};
