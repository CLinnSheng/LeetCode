#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Partition the string into as many part as possible such that each letter appear in at most one part.
 * Eg: "ababcc" can be only partitioned into "abab" & "cc" not "aba" because b is appear in another part
 *
 * Intuition:
 * Since the condition given that each letter can only appear at most one part.
 * So if we traverse thorugh the string let say "ababcc" i want to know which index is the last a which is in the future
 * How can we get it? The only way is we prepoluate by using a hashmap
 * So when we iterate through the string, we must always keep check of the largest end index for every character that we
 * visited. If the index is already greater than the latest index, then that's mean we done for the part. Need to move
 * on to another part
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    std::vector<int> partitionLabels(std::string s)
    {
        if (s.length() == 1)
            return {1};

        std::vector<int> answer;
        std::unordered_map<int, int> charLastIndex;
        for (int i{}; i < s.length(); i++)
            charLastIndex[s[i]] = i;

        int len{1}, lastIndex{charLastIndex[s[0]]};
        for (int index{1}; index < s.length(); index++)
        {
            // over all the character in the part, move on to next part
            if (index > lastIndex)
            {
                answer.emplace_back(len);
                len = 1;
                lastIndex = charLastIndex[s[index]];
            }
            else
            {
                len++;
                lastIndex = std::max(lastIndex, charLastIndex[s[index]]);
            }
        }

        answer.emplace_back(len);
        return answer;
    }
};
