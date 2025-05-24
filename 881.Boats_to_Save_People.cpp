#include <algorithm>
#include <vector>

/*
 * people[i] is the weight of the ith person and an infinite number of boats where each boat
 * can carry a maximum weight of limit. Each boat can carried at most two people at the same time provided
 * the sum of the weight of those people in at most limit.
 *
 * Goal: Return the minimum number of boats to carry every given person
 *
 * Intuition:
 * Each boat can only carry at most 2 person.
 * The first thought comes in mind is we need to sort the array first, so is easier to handle
 * Then we check base cases like if the first people has a weight of limit then straight away return the number of
 * people
 * We need to be greedy to try to fit 2 people every time, but how we do it?
 * So is better to try to allocate the people with greater weight first into the 2 boats, because they take more portion
 * compare to those with lesser weight Therefor, we can use 2 pointer approach
 * Time Complexity: O(nlgn)
 * */
class Solution
{
  public:
    int numRescueBoats(std::vector<int> &people, int limit)
    {
        std::sort(people.begin(), people.end());

        int boats{};
        int n(people.size());

        if (people[0] == limit)
            return n;

        int left{}, right{n - 1};
        while (left <= right)
        {
            int ttlWeight{people[left] + people[right]};
            if (ttlWeight <= limit)
            {
                left++;
                right--;
            }
            else
            {
                right--;
            }

            boats++;
        }

        return boats;
    }
};
