#include <numeric>
#include <vector>
using std::vector;

/*
 * Given an integer array `candies`. candies[i] denotes the size of the pile of candies.
 * Can divide each pile into any number of sub piles but cannot merge 2 piles together.
 * Also given an integer k. Allocate piles of candies to k children such that each child gets the same number of
 * candies. NOTE: Each child can be allocated cnadies from only one pile
 *
 * Goal: Return the maximum number of candies each child can get.
 *
 * Intuition:
 * If the total sum of the candies is less than k then is not possible to distribute.
 * So from here we know that the minimum number of candies can be distributed is 1.
 * From here, we know that there's must be a search space.
 * Whats the maximum number of candies that can be distributed?
 * In best case will be evenly distributing the total number of candies into k children.
 * So the serach space will be [1, ttlSum/k]
 * So, we can just perform binary search from this search space
 *
 * Time Complexity: O(nlgm) where m is the maximum value in the search space
 * */
class Solution
{
  private:
    bool canAllocate(const vector<int> &candies, const long long &k, const long long &numCandies)
    {
        long long nPiles{};

        for (const auto &candy : candies)
            nPiles += candy / numCandies;

        return nPiles >= k;
    }

  public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        // base case check the total sum first
        long long ttlSum{std::accumulate(candies.begin(), candies.end(), 0LL)};
        if (ttlSum < k)
            return 0;

        long long left{1}, right{ttlSum / k};

        // O(lgm)
        while (left <= right)
        {
            long long middle{left + (right - left) / 2};

            // O(n)
            if (canAllocate(candies, k, middle))
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        // O(nlgm)
        return right;
    }
};
