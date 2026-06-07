#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
/*
 * Each digit is map to a set of characters
 * So given a digit we want to find all possible letter combinations
 * 1 important observation here
 * - We need to find out all possible path
 * This lead to backtracking algo
 * */
class Solution
{
  public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty())
        {
            return {};
        }

        // First build the mapping
        std::unordered_map<int, std::string> map;
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";

        std::vector<std::string> ans;
        std::string str{};

        std::function<void(const int)> backtracking = [&](const int index) {
            if (index == digits.length())
            {
                ans.push_back(str);
                return;
            }

            for (const auto ch : map[digits[index] - '0'])
            {
                str += ch;
                backtracking(index + 1);
                str.pop_back();
            }
        };

        backtracking(0);
        return ans;
    }
};
