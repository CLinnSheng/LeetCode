#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Receive a list of non empty strings, words. The words are sorted lexcigoraphically based
 * on the rules of new languages.
 * Goal: Derive the order of letters in this new language.
 *
 * NOTE: String a is lexcigoraphically smaller than string b if either of the following is true:
 * i. First letter differ is smaller in a than b.
 * ii. a is prefix of b and a.length < b.length
 *
 * Intuition:
 * We can treat each character as a node in the graph. Then the edge will be the order of the new langauges.
 * So basically we will form a graph of edges to find which word come after which word.
 * We also need to use inDegree. This indegree can help us determine whether does any character come before this
 * character or not
 *
 * Time Complexity: O(L + E + V)
 * */
class Solution
{
  public:
    std::string foreignDictionary(std::vector<std::string> &words)
    {
        std::string ans{};
        std::unordered_map<char, std::unordered_set<char>> graph;
        std::unordered_map<char, int> inDegree;

        // Initialize
        // O(L)
        for (const auto &word : words)
            for (const auto &ch : word)
            {
                graph[ch] = std::unordered_set<char>();
                inDegree[ch] = 0;
            }

        // O(L)
        for (int word{}; word < words.size() - 1; word++)
        {
            std::string currWord{words[word]}, nextWord{words[word + 1]};
            int minLen(std::min(currWord.length(), nextWord.length()));

            // Base Case Checking
            if (currWord.length() > nextWord.length() && currWord.substr(0, minLen) == nextWord.substr(0, minLen))
                return "";

            for (int i{}; i < minLen; i++)
            {
                // Check whether got same character or not
                if (currWord[i] != nextWord[i])
                {
                    if (!graph[currWord[i]].count(nextWord[i]))
                    {
                        graph[currWord[i]].insert(nextWord[i]);
                        inDegree[nextWord[i]]++;
                    }
                    break;
                }
            }
        }

        std::deque<char> queue;
        // Push those with 0 degree, means no 1 is depends on it. Then
        // it will be the first few character in the dictionary
        // O(V)
        for (const auto &[ch, freq] : inDegree)
            if (freq == 0)
                queue.emplace_back(ch);

        // O(E)
        while (!queue.empty())
        {
            auto currChar{queue.front()};
            queue.pop_front();

            ans += currChar;

            for (const auto &neigh : graph[currChar])
                // Only push when is equal to 0
                // means no character comes before it
                if (--inDegree[neigh] == 0)
                    queue.emplace_back(neigh);
        }
        return inDegree.size() == ans.length() ? ans : "";
    }
};
