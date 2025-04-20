#include <unordered_map>
#include <vector>

/*
 * answers[i] is the answer of the ith rabbit on how many rabbits have the same color as you
 *
 * Goal: Return the minimum number of rabbits that could be in the forest
 *
 * Intuition:
 * From the given example, answers = [1, 1, 2]
 * First and second rabbit have the same answer which is 1, which means that they are on the same color group
 * Since both of them answer 1 which means there exists another 1 rabbit with the same color.
 * Thus, the color group size of it will be 2.
 * Then rabbit index 2 answer 2 means there is another 2 rabbit have the same color as its.
 * Means that this color group has 3 rabbits
 * In total, there will be 5 rabbit
 *
 * So what we observed from this example is, when rabbit has the same answer they are most likely from the same group.
 * But this is not always true,
 * eg: [1, 1, 1]
 * if we take from what we mentioned just now it the number of rabbit should be 3, but this is not true.
 * Because every rabbit says it has 1 rabbit with the same color, the color group should be only have 2 rabbit but we
 * said 3. So the number of color group with size 2 can be computed with (group size + no_group)/group_size Hence, the
 * number of rabbit should be 4.
 *
 * We need a hash map to keep track of the number of color group
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int numRabbits(std::vector<int> &answers)
    {
        std::unordered_map<int, int> group;
        for (const int &ans : answers)
            group[ans]++;

        int rabbits{};

        for (const auto &[val, cnt] : group)
        {
            int group_size{val + 1};

            int no_of_group{(cnt + val) / group_size};

            rabbits += no_of_group * group_size;
        }
        return rabbits;
    }
};
