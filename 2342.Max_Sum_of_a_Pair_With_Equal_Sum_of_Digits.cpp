#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

/*
 * Goal: Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices of i & j  that
 * Condition: choose 2 indices i & j such that i != j and the sum of digits of the number nums[i] == nums[j]
 *
 * Intuition:
 * What we really care about is the sum of digits of the nums[i]
 * We can use a hash map to map the sum of digit to the nums[i] and then w
 * since we need to find 2 sum of digits which are equal, we can actually map int to a priority queue specifically
 * minHeap So we makesure that the queue only has 2 val and remove the smallest whenever we have more than 2 Time
 * Complexity: O(nlgn) Space Complexity: O(n)
 * */
class Solution
{
  private:
    int sumofDigit(int n)
    {
        int sum{};
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    struct comparator
    {
        constexpr bool operator()(const int &a, const int &b)
        {
            return a > b;
        }
    };

  public:
    int maximumSum(std::vector<int> &nums)
    {
        std::unordered_map<int, std::priority_queue<int, std::vector<int>, comparator>> map;

        for (const auto &num : nums)
        {
            int sumDigit{sumofDigit(num)};
            map[sumDigit].emplace(num);

            if (map[sumDigit].size() > 2)
                map[sumDigit].pop();
        }

        int answer{-1};
        for (auto &[_, minHeap] : map)
            if (minHeap.size() == 2)
            {
                int firs{minHeap.top()};
                minHeap.pop();
                int sec{minHeap.top()};
                answer = std::max(answer, firs + sec);
            }
        return answer;
    }
};
