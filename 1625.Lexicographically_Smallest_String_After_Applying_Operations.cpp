#include <deque>
#include <string>
#include <unordered_set>
/*
 * Given a string s of even length consisting digits 0-9 and 2 integers a & b.
 * Apply either following 2 operations any number of times and in any order
 * 1. Add a to all odd indices of s. Digits post 9 are cycled back to 0.
 * 2. Rotate s to the right by b positions
 *
 * Goal: Return the lexicographically smallest string that you can obtain by applying the above operations any number of
 * times on s.
 *
 * Intuition:
 * Need to build the lexicographically smllest string.
 * We can just enumerate it
 * Time Complexity: O(n^2) Looping it cost o(n) and doing the operation another O(n)
 * */
class Solution
{
  private:
    std::string addOperation(std::string &s, int a)
    {
        std::string tmp{s};

        for (int i{1}; i < s.length(); i += 2)
        {
            int val = tmp[i] - '0';
            val = (val + a) % 10;
            tmp[i] = val + '0';
        }

        return tmp;
    }

    std::string rotateOperation(std::string s, int b)
    {
        int len(s.length());
        int rotation{b % len};

        return s.substr(rotation) + s.substr(0, rotation);
    }

  public:
    std::string findLexSmallestString(std::string s, int a, int b)
    {
        std::unordered_set<std::string> set;
        std::deque<std::string> queue;
        std::string ans{s};

        set.insert(s);
        queue.emplace_back(s);

        while (!queue.empty())
        {
            std::string currStr = queue.front();
            queue.pop_front();

            if (currStr < ans)
                ans = currStr;

            std::string addStr{addOperation(currStr, a)};
            if (set.find(addStr) == set.end())
            {
                set.insert(addStr);
                queue.emplace_back(addStr);
            }

            std::string rotateStr{rotateOperation(currStr, b)};
            if (set.find(rotateStr) == set.end())
            {
                set.insert(rotateStr);
                queue.emplace_back(rotateStr);
            }
        }

        return ans;
    }
};
