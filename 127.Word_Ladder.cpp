#include <algorithm>
#include <cstddef>
#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Goal: Transform beginWord into endWor by following these rules:
 * i. can transform beginWord to any word within the list, provided that exactly one position the words have a
 * different character, and the rest must be the same
 *
 * Intuition:
 * At each transformation only one character change for eg: hot -> hat.
 * We can treat every single word as a node in a graph. Then for example bag can be transform into sag or dag.
 * So we need to build an adjList that map a word that can possible transform to all other words
 * DFS / BFS both work but bfs will be much more simple to implement
 * Time Complexity: O(m * n)
 * */

class Solution
{
  public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
    {
        // Base Case
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        std::unordered_map<std::string, std::vector<std::string>> mapping;
        for (const auto &word : wordList)
        {
            for (int index{}; index < word.length(); index++)
            {
                std::string possibleStr = word.substr(0, index) + "*" + word.substr(index + 1);
                mapping[possibleStr].emplace_back(word);
            }
        }

        std::deque<std::string> queue;
        queue.emplace_back(beginWord);

        // Prevent looping
        std::unordered_set<std::string> visited;
        int answer{1};

        while (!queue.empty())
        {
            std::size_t size{queue.size()};

            for (int i{}; i < size; i++)
            {
                auto currStr{queue.front()};
                queue.pop_front();

                if (currStr == endWord)
                    return answer;

                // masking every single character to find all possible transformation
                for (int index{}; index < currStr.length(); index++)
                {
                    auto possibleStr = currStr.substr(0, index) + "*" + currStr.substr(index + 1);

                    for (const auto &transformStr : mapping[possibleStr])
                        if (visited.find(transformStr) == visited.end())
                        {
                            queue.emplace_back(transformStr);
                            visited.emplace(transformStr);
                        }
                }
            }
            answer++;
        }

        return 0;
    }
};
