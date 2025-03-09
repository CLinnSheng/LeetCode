/*
 * Given an input array, color and an integer k.
 * color[i] = 0/1,
 * An alternating group is every k contiguous tiles in the cricle with alternating colors/value.
 * The first and last tiles are considered to be next to each other
 * Goal: Return the number of alternating groups
 *
 * Intuition:
 * The array is in circular. So for eg: 0,1,0,1,0 has 5 subarray of size 3.
 * The initial thought is using sliding window of size k. But how do we check the subarray has alternating colour or
 * not? We can check the window every time but this will lead to O(n*k) Is there a better way to check? We need to check
 * whether i is diff from i - 1 or not, if it is then move the right pointer and repeat the process until it reach size
 * k. Otherwise straight move the left pointer to the right pointer position because there is no point continuing this
 * window because it already violates the alternating value rules
 * */
#include <vector>
using std::vector;

class Solution
{
  public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int answer{}, size(colors.size());

        int left{}, right{1};
        for (; right < size + k - 1; right++)
        {
            // check whether is it alternating or not
            if (colors[right % size] == colors[(right - 1) % size])
                // if not alteranting move the left pointer
                // because there is no point to continue on this subarray
                left = right;

            if (right - left + 1 > k)
                left++;
            if (right - left + 1 == k)
                answer++;
        }

        return answer;
    }
};
