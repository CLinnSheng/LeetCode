#include <algorithm>
#include <queue>
#include <vector>

/*
 * queries[i] = [li, ri].
 * Each queries[i] represents the following action on nums:
 * - Decrement the value at each index in the range [li, ri] in nums by at most 1.
 * - The amount by which the value is decremented can be chose independently for each index.
 * Goal: Return the maximum number of elements that can be removed from queries, such
 * that nums can still be converted to zero array using the remaining queries.
 *
 * Intuition:
 * Take note that we can select freely which query to process, so is also the same we can
 * choose whichever query we want to remove.
 * How can we do this? So our goal is try to make the array to all zeros.
 * So we need to be greedy, for every query we pick it must cover the longest range.
 * So we need to decrement the value from the first index to the last index.
 * Therefor, we need to process those query that start at i, and then for those query that start from i?
 * Which 1 shall we pick while it still not zero? We always pick the 1 that covers the longest until it become zero
 * Time Complexity: O(mlgm + n * m lg mn)
 * */
class Solution
{
  public:
    int maxRemoval(std::vector<int> &nums, std::vector<std::vector<int>> &queries)
    {
        // Sort the query first, in order to decrement the val in nums in the correct sequence
        std::sort(queries.begin(), queries.end(), [](const std::vector<int> &n1, const std::vector<int> &n2) {
            // ascending order
            return n1[0] < n2[0];
        });

        // this heap store the right boundary of queries, as try to pick the 1 that covers the largest range
        std::priority_queue<int> maxHeap;
        std::vector<int> decrement_interval(nums.size() + 1, 0);
        int operations{};

        // process the query based on the curr index in nums
        for (int i{}, j{}; i < nums.size(); i++)
        {
            operations += decrement_interval[i];
            while (j < queries.size() && queries[j][0] == i)
            {
                maxHeap.emplace(queries[j][1]);
                j++;
            }

            // Since we gather all the query that start with i, then now we will see how many query needed in order
            // to make nums[i] ---> 0
            // always take those query cover the longest
            while (operations < nums[i] && !maxHeap.empty() && maxHeap.top() >= i)
            {
                operations++;
                decrement_interval[maxHeap.top() + 1]--;
                maxHeap.pop();
            }

            if (operations < nums[i])
                return -1;
        }
        return maxHeap.size();
    }
};
