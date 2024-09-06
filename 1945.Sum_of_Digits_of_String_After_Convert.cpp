#include <ios>
#include <string>
#include <iostream>

/*
Goal return the resulting integer after performing k times of the operation
Intuition: First Conver the character into the integer first and since k >= 1 so we do the first operation
And then just keep looping and do it until k==0
*/

class Solution
{
public:
    int getLucky(std::string s, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::string converted_str = "";

        for (const auto&c : s)
            converted_str += std::to_string(c - 'a' + 1);

        while (k-- > 0)
        {
            int res = 0;

            for (const auto& c : converted_str)
                res += static_cast<int>(c - '0');

            if (k == 0)
                return res;

            converted_str = std::to_string(res);
        }

        return -1;
    }
};
