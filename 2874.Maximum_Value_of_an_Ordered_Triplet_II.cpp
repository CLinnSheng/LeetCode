#include <algorithm>
#include <vector>

/*
 * Same with question 2874.
 *
 * Intuition:
 * We only need to find those result in positive for nums[i] - nums[j]
 * So we need to be greedy to maximize nums[i] & nums[k]
 * In the previous question we use space complexity of O(n)
 * But do we really need an array to store the prefix max of every single index?
 * Actually no, we can actually just use a variable to store the current prefixmax
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * */
class Solution
{
  public:
    long long maximumTripletValue(std::vector<int> &nums)
    {
        long long answer{};
        long long prefixMax{nums[0]}, maxDiff{};

        // just moving the k pointer
        for (int i{2}; i < nums.size(); i++)
        {
            // update the answer first
            answer = std::max(answer, maxDiff * nums[i]);

            // then only update the prefixMax & maxDiff
            prefixMax = std::max(prefixMax, (long long)nums[i]);
            maxDiff = std::max(maxDiff, prefixMax - nums[i]);
        }

        return answer;
    }
};
