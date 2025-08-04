#include <functional>
#include <queue>
#include <string>
#include <utility>
#include <vector>

/*
 * only contains "a", "b" & "c"
 * does not contain "aaa", "bbb" & "ccc"
 * s contain at most a occurences of "a" for b and c as well
 *
 * Goal: Find the longest possible happy string.
 *
 * Intuition:
 * We need to find the longest possible string, then we have to be greedy while picking it.
 * Always choose the 1 with the most freq first
 * We can make use of a maxHeap
 * Time Complexity: O(nlgn)
 * */
class Solution
{
  public:
    std::string longestDiverseString(int a, int b, int c)
    {
        std::string answer{};
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>>
            maxHeap;

        if (a)
            maxHeap.emplace(a, 'a');
        if (b)
            maxHeap.emplace(b, 'b');
        if (c)
            maxHeap.emplace(c, 'c');

        while (!maxHeap.empty())
        {
            auto [currFreq, currChar] = maxHeap.top();
            maxHeap.pop();

            // Handle 3 consecutive same characters
            if (answer.length() >= 2 && currChar == answer[answer.length() - 1] &&
                answer[answer.length() - 2] == currChar)
            {
                // If no more work then finish
                if (maxHeap.empty())
                    break;

                auto [nxtFreq, nxtChar] = maxHeap.top();
                maxHeap.pop();

                answer += nxtChar;
                nxtFreq--;

                // if still have then put it back
                if (nxtFreq)
                    maxHeap.emplace(nxtFreq, nxtChar);
            }
            else
            {
                answer += currChar;
                currFreq--;
            }

            // Put it back no matter got use or not
            if (currFreq)
                maxHeap.emplace(currFreq, currChar);
        }
        return answer;
    }
};
