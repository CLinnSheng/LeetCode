#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Each digit is mapped to a set of character as shown below
 * Goal: Return all possible letter combinations that digits could represent
 *
 * Intuition:
 * This is a decision tree problem where at every index we need to choose which character and also need to try all
 * possible combinations that means we need to back tracking
 * */
class Solution
{
  private:
    std::unordered_map<int, std::string> map;

    void helper()
    {
        map[0] = "+";
        map[1] = "";
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
    }

  public:
    Solution()
    {
        helper();
    }

    std::vector<std::string> letterCombinations(std::string digits)
    {
        std::vector<std::string> answer;
        std::string str{};

        if (digits.empty())
            return {};

        std::function<void(const int &)> dfs_backtracking = [&](const int &index) {
            if (index == digits.length())
            {
                answer.emplace_back(str);
                return;
            }

            auto &mapStr{map[digits[index] - '0']};

            for (const auto &ch : mapStr)
            {
                str += ch;
                dfs_backtracking(index + 1);

                // backtracking
                str.pop_back();
            }
        };

        dfs_backtracking(0);
        return answer;
    }
};
