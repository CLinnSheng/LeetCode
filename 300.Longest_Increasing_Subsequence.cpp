#include <vector>

/*
 * Goal: Return the length of the longest strictly increasing subsequence
 *
 * Intuition:
 * Subsequence is a sequence that can be derived by deleting some of the elements
 * By brute force we can try to start from every index since we finding the subsequence
 * And at every index we can choose to include or not, information we need to pass is index and also last element index
 * Time Complexity will be O(2^N)
 * Can be improve by caching where caching[i] = longest subsequence from i to n
 * Time Complexity: O(n^2)
 * So the caching dimension normally is determined by the information that passed down the recursive function
 * */
class Solution
{
  private:
    int dfs(const int currIndex, const int prevIndex, const std::vector<int> &nums,
            std::vector<std::vector<int>> &caching)
    {
        if (currIndex == nums.size())
            return 0;

        if (caching[currIndex][prevIndex + 1] != -1)
            return caching[currIndex][prevIndex + 1];

        // Not include
        int size{dfs(currIndex + 1, prevIndex, nums, caching)};

        // Include but check whether is it increasing
        if (prevIndex == -1 || nums[prevIndex] < nums[currIndex])
            size = std::max(1 + dfs(currIndex + 1, currIndex, nums, caching), size);

        return caching[currIndex][prevIndex + 1] = size;
    }

  public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        int n(nums.size());
        if (n == 1)
            return 1;

        std::vector<std::vector<int>> caching(n, std::vector<int>(n, -1));
        return dfs(0, -1, nums, caching);
    }
};
