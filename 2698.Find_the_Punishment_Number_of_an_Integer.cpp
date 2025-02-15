/*
 * Punishment Number of n is defined:
 * 1. 1 <= i <= n
 * 2. Decimal representation of i * i can be partitioned into contiguous substring such that the sum equals i
 * e: 36 * 36 = 1296 --> 12 + 9 + 6
 *
 * Intuiion:
 * Decision Branching Problem
 * eg: when index at 0 we can branch into (1296)
 * 1 or 12 or 129 or 6
 * We can just simply run the stimulation with recursive
 *
 * */
#include <functional>
#include <string>
#include <string_view>
class Solution
{
  public:
    int punishmentNumber(int n)
    {
        int answer{};

        std::function<bool(const int &, const int &, const int &, const std::string_view &)> partition =
            [&, n](const int &currIndex, const int &currSum, const int &target, const std::string_view &str) {
                // if already reach end of the string check whether is the partition successfull
                if (currIndex == str.length())
                    return currSum == target;

                // if the currentSum already greater than target, then adding the number after the currentindex will
                // definitely greater than target
                if (currSum > target)
                    return false;

                // Lets say the maximum length of possible str is L
                // then at worst we only choose 1 value every single time
                // therefore --> O(L^2)
                for (int i{currIndex}; i < str.length(); i++)
                {
                    std::string temp{str.substr(currIndex, i - currIndex + 1)};
                    if (partition(i + 1, currSum + std::stoi(temp), target, str))
                        return true;
                }
                return false;
            };

        // O(n)
        for (int i{1}; i <= n; i++)
            if (partition(0, 0, i, std::to_string(i * i)))
                answer += i * i;
        return answer;
    }
};
