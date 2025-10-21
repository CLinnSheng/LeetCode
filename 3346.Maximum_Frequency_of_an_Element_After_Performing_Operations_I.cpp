#include <algorithm>
#include <cstdlib>
#include <vector>
/*
 * Select an index i that was not selected in an previous operations then add an integer in the range[-k,k] to nums[i]
 * Goal: Return the maximum possible frequency of any element in nums after performing the operations
 *
 * Intuition:
 * We need to keep track of the frequency of each element
 * Since the range is in [-k,k] means we can add 0
 * This is actually kind of a interval problem and prefix sum problem
 * We can maintain a prefix sum array, so we can easily find out the frequency of element in the range
 * This will be just the raw element without any operation then we need to add with element that involved operations.
 * Time Complexity O(n)
 * */

class Solution
{
  public:
    int maxFrequency(std::vector<int> &nums, int k, int numOperations)
    {
        int maxElement = *std::max_element(nums.begin(), nums.end()) + k + 2;
        // cnt[i] is the frequency of element up to i
        int *cnt = new int[maxElement]();

        for (const int num : nums)
            cnt[num]++;

        for (int i{1}; i < maxElement; i++)
            cnt[i] += cnt[i - 1];

        int answer{};

        for (int i{}; i < maxElement; i++)
        {
            // Left Boundary of the [-k, k] range
            int left = std::max(0, i - k);
            // Right Boundary
            int right = std::min(i + k, maxElement - 1);

            // Then find number of element in the range
            int numInRange = cnt[right] - (left == 0 ? 0 : cnt[left - 1]);

            // Then get the frequency of element i
            int freq = cnt[i] - (i == 0 ? 0 : cnt[i - 1]);

            // Then compute the total sum of element i
            answer = std::max(answer, freq + std::min(numOperations, numInRange - freq));
        }

        return answer;
    }
};
