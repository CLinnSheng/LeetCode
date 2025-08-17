#include <deque>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

/*
 * Lock with 4 circular wheel. Each wheel has 10 slots
 * Wheel can rotate freely. Initially start at "0000"
 * Each move turning one wheel at one slot
 * Given a list of deadends, if lock displaying any of these number, wheel of lock will stop
 * Goal: Return the minimum number of turns to reach target otherwise -1
 *
 * Intuition:
 * We can treat each number as a node. So we think of it as a graph.
 * So is either DFS / BFS. Since the question is asking for finding the minimum number, so we can only use
 * BFS.
 *
 * Time Complexity: O(m)
 * */
class Solution
{
  private:
    std::vector<std::string> helper(const std::string &str)
    {
        std::vector<std::string> possibleStr;

        for (int i{}; i < 4; i++)
        {
            std::string temp{str};

            // + 1
            temp[i] = ((temp[i] - '0' + 1) % 10) + '0';
            possibleStr.emplace_back(temp);

            // -1
            temp = str;
            temp[i] = ((temp[i] - '0' + 9) % 10) + '0';
            possibleStr.emplace_back(temp);
        }

        return possibleStr;
    }

  public:
    int openLock(std::vector<std::string> &deadends, std::string target)
    {
        std::unordered_set<std::string> visited(deadends.begin(), deadends.end());
        // edge case
        if (visited.find("0000") != visited.end())
            return -1;

        std::deque<std::pair<std::string, int>> queue;
        queue.emplace_back("0000", 0);
        visited.insert("0000");

        while (!queue.empty())
        {
            auto front{queue.front()};
            queue.pop_front();

            if (front.first == target)
                return front.second;

            for (const auto &children : helper(front.first))
            {
                if (visited.find(children) == visited.end())
                {
                    visited.insert(children);
                    queue.emplace_back(children, front.second + 1);
                }
            }
        }
        return -1;
    }
};
