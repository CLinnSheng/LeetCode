#include <functional>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

/*
 * fruits[i] - quantity of the ith type fruit
 * baskets[j] - capacity of the jth basket
 * Rule:
 * - Placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type
 * - Each basket can hold only one type of fruit
 * - Fruit type cannot be placed in any basket, it remains unplaced
 *
 * Goal: Return the number of fruit types that remain unplaced after all possible allocations are made
 *
 * Intuition:
 * We need to be greedy while placing the fruit, placed the most fruit with the most available basket
 * */
class Solution
{
  public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n(fruits.size()), answer{};
        vector<bool> used(n, false);

        for (int fruit{}; fruit < n; fruit++)
        {
            bool canBePlace{false};

            for (int basket{}; basket < n; basket++)
            {
                if (used[basket] && baskets[basket] >= fruits[fruit])
                {
                    canBePlace = true;
                    used[basket] = true;
                }
            }
        }
    }
};
