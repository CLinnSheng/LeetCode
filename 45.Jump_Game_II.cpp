#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>
/*
 * Return the minimum number of jumps to reach the last position
 *
 * Intuition: The brute force way will just simply try all possible length of jump
 * From the brute force we can see we doing some subproblem multiple times and then we can enchacne it through caching
 *
 * Or another approach is being greedy, we try to go as further away as possible for every move but still checking
 * whether has we reach the final element or not. Having a range of number we can land on then check whether the right
 * boundary is already at last element or not
 * */
class Solution
{
  private:
    int dfs(const std::vector<int> &nums, const int index, std::unordered_map<int, int> &caching)
    {
        if (index == nums.size() - 1)
            return 0;

        if (nums[index] == 0)
            return 100000;

        if (caching.find(index) != caching.end())
            return caching[index];

        int end = std::min(int(nums.size()), index + nums[index] + 1);
        int answer = 100000;
        for (int i{index + 1}; i < end; i++)
            answer = std::min(answer, 1 + dfs(nums, i, caching));

        return caching[index] = answer;
    }

  public:
    int jump(std::vector<int> &nums)
    {
        // std::unordered_map<int, int> caching;
        // return dfs(nums, 0, caching);

        // Left & Right boundary
        int left{}, right{};
        int answer{};

        while (right < nums.size() - 1)
        {
            // Track how far can we go from left
            int furthest = 0;
            for (int index{left}; index <= right; index++)
                furthest = std::max(furthest, index + nums[index]);

            left = right + 1;
            right = furthest;
            answer++;
        }
        return answer;
    }
};
