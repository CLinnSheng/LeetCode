
#include <algorithm>
#include <vector>
/*
 * Burst ith balloon will receive nums[i - 1] + nums[i] + nums[i + 1]
 * if i - 1 or i + 1 goes out of range, then assume the out of bound value is 1
 * Goal: Return the maximum number of coins you can receive by bursting all of the balloons
 *
 * Intuition:
 * The brute force will be at each index we will either choose to burst or skip it while going down the recursive
 * append 1 at both end and then pass the boundary left and right
 * Time Complexity: O(2^n * n)
 *
 * How can we optimize it? If you observe from brute force, we are doing repetitive task
 * We can optimize it by using cache/memoziation
 *
 * But the problem now is we not passing any information but just the new vector everything
 * So it will be a little bit tricky to do cache so from the new vector,
 * we are removing the pop balloon.
 * so instead of passing which balloon is pop, we pass the boundary of left and right then within the boundary
 * find which balloon popping return the most. So is like which 1 is burst last
 * Time Complexity:  O(n^3)
 * */
class Solution
{
  private:
    int dfs(std::vector<int> &nums, std::vector<std::vector<int>> &cache, int left, int right)
    {
        if (left > right)
        {
            return 0;
        }

        if (cache[left][right] != -1)
        {
            return cache[left][right];
        }

        int maxPoints{};
        for (int index{left}; index <= right; index++)
        {
            int points = nums[left - 1] * nums[index] * nums[right + 1];
            points += dfs(nums, cache, left, index - 1) + dfs(nums, cache, index + 1, right);

            maxPoints = std::max(maxPoints, points);
        }

        return cache[left][right] = maxPoints;
    }
    int bruteForce(std::vector<int> &nums)
    {
        // Edge Case
        if (nums.size() == 2)
        {
            return 0;
        }

        int maxPoints{};

        for (int i{1}; i < nums.size() - 1; i++)
        {
            int points = nums[i - 1] * nums[i] * nums[i + 1];
            std::vector<int> temp(nums);
            temp.erase(temp.begin() + i);

            maxPoints = std::max(maxPoints, points + bruteForce(temp));
        }
        return maxPoints;
    }

  public:
    int maxCoins(std::vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        std::vector<std::vector<int>> cache(nums.size() + 1, std::vector<int>(nums.size() + 1, -1));

        // 1,1,2,3,4,1
        return dfs(nums, cache, 1, nums.size() - 2);
    }
};
