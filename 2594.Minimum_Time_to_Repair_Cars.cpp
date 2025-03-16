#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
using std::vector;

/*
 * Given an integer array ranks representing the ranks of some mechanics.
 * ranks[i] is then rank of the machnic
 * rank 'r' can repair n cars in r * n^2 minutes
 *
 * Goal: Return the minimum time taken to repair all the cars.
 * NOTE: All the machanics can repair the cars simultaneously
 *
 * Intuition:
 * From the goal, i can tell need to use binary search because of the minimum time.
 * So we need to search through a search space and then check with the middle value and see whether
 * can we repair it anot within the middle value time.
 * Time Complexity: O(nlgm)
 * */
class Solution
{
  public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        // search space: [Low, High]
        // Equation of time = rank * n^2
        // The lowest can be 1 minute only, while the maximum will be highest rank mechanice done all the repair
        // search space: [1, max(ranks) * n * n]
        long long left{}, right{(long long)ranks[0] * cars * cars};
        long long answer{};

        // this function will check how many cars can be repaired in time, time
        std::function<bool(const long long &)> helper = [&ranks, &cars](const long long &time) {
            long long n_cars{};

            for (const auto &rank : ranks)
                n_cars += (long long)(std::sqrt(time / (double)rank));
            return n_cars >= cars;
        };

        while (left <= right)
        {
            long long middle{left + (right - left) / 2};

            if (helper(middle))
            {
                right = middle - 1;
                answer = middle;
            }
            else
                left = middle + 1;
        }
        return answer;
    }
};
