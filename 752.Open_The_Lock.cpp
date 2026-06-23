#include <deque>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

/*
 * Start to search from 0000 to target
 * So we can imagine each string is a node then each possible string is the child node
 * So this can be solve with DFS/BFS --> Graph Problem
 * Since finding minimum BFS will be much more easier
 * We can store the list of deadends in a set, so we can check it with O(1)
 * At every moment we have 8 choices where we can choose 1 of the 4 wheel to go up & down
 * So basically we will try all possible choices
 * Time Complexity: O(10^4)
 * */

class Solution
{
  private:
    std::vector<std::string> helper(const std::string &str)
    {
        std::vector<std::string> strings;

        // Try all 4 wheels
        for (int i{}; i < 4; i++)
        {
            std::string temp{str};
            // +1
            temp[i] = ((temp[i] - '0' + 1) % 10 + '0');
            strings.emplace_back(temp);

            // -1
            temp = str;
            temp[i] = ((temp[i] - '0' + 9) % 10 + '0');
            strings.emplace_back(temp);
        }

        return strings;
    }

  public:
    int openLock(std::vector<std::string> &deadends, std::string target)
    {
        std::unordered_set<std::string> set(deadends.begin(), deadends.end());

        // Edge Case
        if (set.find("0000") != set.end())
        {
            return -1;
        }

        std::deque<std::pair<std::string, int>> queue;
        queue.emplace_back("0000", 0);
        set.insert("0000");

        while (!queue.empty())
        {
            auto currLock = queue.front();
            queue.pop_front();

            if (currLock.first == target)
            {
                return currLock.second;
            }

            for (const auto &str : helper(currLock.first))
            {
                // Check is it in the dead end
                if (set.find(str) != set.end())
                {
                    continue;
                }

                queue.emplace_back(str, currLock.second + 1);
                set.insert(str);
            }
        }

        return -1;
    }
};
