#include <algorithm>
#include <cmath>
#include <deque>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

/*
 * Start with score 1. Goal is to maximize the score by applying the following operation at most k times:
 * i. Choose any empty subarray that haven chosen previously.
 * ii. Choose an element x of the subarray with the highest prime score. Choose the smallest index, if having multiple
 * element with the same prime score. iii. Multiply the score by x. Prime Score: Number of distinct prime factor of x.
 * eg: 300 is 3 where 300 = 2 * 2 * 3 * 5 * 5
 *
 * Goal: Return the maximum possible score
 *
 * Intuition:
 * the score is keep multiplying by x. So we want to be greedy such that for every subarray that we choose, the highest
 * prime score in the subarray is actually the highest element in the subarray or the entire array.
 * We can preprocess the primescore for each element
 * So how can we choose the subarray? We can choose by letting the highest 'x' element as the center.
 * So we will try to move to the left and see how far can we go such that it still remain the highest prime score and
 * also the same for the right
 * One important observation is, the element itself also consider a subarray.
 * So how can we find the left and right boundary of the maximum element or every single element?
 * We can do preprocessing by iterating through the array and thus can done in O(n) time.
 * Another key observatoin is that the number of possible subarray for a single element is just simply the (index -
 * leftboundary) * (rightboundary - index) The preprocessing can be done by using a stack.
 * */
class Solution
{
  private:
    const int MOD = 1e9 + 7;
    // Helper function to compute the power of a number modulo MOD
    // O(lg exponent)
    long long power(long long base, long long exponent)
    {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0)
        {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1)
            {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }

  public:
    int maximumScore(std::vector<int> &nums, int k)
    {
        int n(nums.size());
        int ans{1};

        // 1. Preprocessing the prime score
        // O( n * sqrt(m) )
        std::vector<int> primeScores;
        for (auto num : nums)
        {
            int score{};

            for (int factor{2}; factor <= std::sqrt(num); factor++)
            {
                // if is a factor then increase the score
                if (num % factor == 0)
                {
                    score++;
                    // to deal with the same prime factors
                    while (num % factor == 0)
                        num /= factor;
                }
            }

            // handle cases where it cannot be factor into 1
            if (num >= 2)
                score++;

            primeScores.emplace_back(score);
        }

        // 2. Preprocessing the left & right boundary for every single element
        //  -1 means the left boudary is before the first element & n means the right boundary is after the last
        //  element
        std::vector<int> leftBoundary(n, -1), rightBoundary(n, n);
        // indices of decreasing or equal order scores
        std::deque<int> stack;
        // O(n)
        for (int index{}; index < n; index++)
        {
            // find the right boundary of the top element
            // take note is smaller than not smaller or equal
            // this is because if we consider equal then is wrong already the equal element left boundary shouldnt be
            // the same with the top of the stack element
            while (!stack.empty() && primeScores[stack.back()] < primeScores[index])
            {
                auto stackindex{stack.back()};
                stack.pop_back();

                // since we find the first element has higher score than the top of the stack
                // then this is the right boundary
                rightBoundary[stackindex] = index;
            }
            // left boundary because the stack is storing decreasing prime score or equal
            // so the left bondary of the current element is just simply the top element in the stack
            if (!stack.empty())
                leftBoundary[index] = stack.back();

            stack.emplace_back(index);
        }

        // 3. Now find compute the score
        // Since we want to get the maximum score, we need to be greedy by starting out with the highest element in the
        // array
        // O(nlgn)
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>>
            maxHeap;
        for (int i{}; i < n; i++)
            maxHeap.emplace(std::pair<int, int>{nums[i], i});

        // O(lgk)
        // because the power functoin takes O(lg exponent) & the k each time is minus by nOperations
        // We can assume it is bounded by O(lgk)
        while (k > 0)
        {
            auto [val, index]{maxHeap.top()};
            maxHeap.pop();

            long long nSubArrays((rightBoundary[index] - index) * (index - leftBoundary[index]));
            long long nOperations{std::min((long long)k, nSubArrays)};

            ans = (ans * power(val, nOperations)) % MOD;
            k -= nOperations;
        }

        return ans;
    }
};
