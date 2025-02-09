#include <unordered_map>
#include <vector>
using ll = long long;
using std::vector;

/*
 * A pair of indicies (i, j) is a bad pair if i < j && j - i != nums[j] - nums[i]
 * Goal: Return the number of bad pairs in nums
 *
 * Intuition:
 * The brute force way will be O(n^2) by using a double loop
 *
 * Can we further optimize it to O(n)?
 * Notice that j - i != nums[j] - nums[i] --> j - nums[j] != i - nums[i] or nums[j] - j != nums[i] - i
 * Instead of finding the bad pairs how about we find the number of good pair. This is because
 * finding the number of bad pair we need to know the future but we cant, but finding the number of good pair we can
 * know it from the past
 * at ith index there are simple i possible pair to form nums[i]
 * */
class Solution
{
  public:
    ll countBadPairs(vector<int> &nums)
    {
        ll answer{};
        // diff -> freq
        std::unordered_map<int, int> diffCnt;

        for (int i{}; i < nums.size(); i++)
        {
            int diff{i - nums[i]};

            // getting the number of element with the same diff, so it will form a good pair
            int goodPairCnt{diffCnt[diff]};

            // number of bad pair just simply take the total nubmer of possible pair formed from 0 to i & then subtract
            // it with number of good pair
            answer += i - goodPairCnt;

            diffCnt[diff] += 1;
        }
        return answer;
    }
};
