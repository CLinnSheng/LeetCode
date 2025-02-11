#include <deque>
#include <string>
#include <string_view>

/*
 * Goal: Return s after removing all occurences of part.
 *
 * Intuition:
 * After remove a part there might be a new occurence of pattern
 * eg: ababcc , pattern = abc ababcc -> abc -> ""
 * Maybe we can use a stack to store the characters, and only check if the top of the stack match with the last
 * character of part
 *
 * Time Complexity: O(nm)
 * */
class Solution
{
  private:
    bool helper(const std::deque<char> &stack, const std::string_view &part, const int &len_part)
    {
        std::deque<char> temp(stack);
        for (int part_ptr{len_part - 1}; part_ptr >= 0; part_ptr--)
            // check whether it matches or not
            // if one doesnt match dont have to continue
            if (temp.back() != part[part_ptr])
                return false;
            else
                temp.pop_back();
        return true;
    }

  public:
    std::string removeOccurrences(std::string s, std::string part)
    {
        std::deque<char> stack;
        int len_s(s.length()), len_part(part.length());

        for (int i{}; i < len_s; i++)
        {
            stack.emplace_back(s[i]);

            if (stack.back() == part[len_part - 1] && stack.size() >= len_part)
            {
                if (helper(stack, part, len_part))
                {
                    int cnt{};
                    while (cnt < len_part)
                    {
                        stack.pop_back();
                        cnt++;
                    }
                }
            }
        }
        return std::string(stack.begin(), stack.end());
    }
};
