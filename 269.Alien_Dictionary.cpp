#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Goal: Derive the order of letters in this language, if order is invalid
return empty string and if there are multiple of them return any
 *
 *
 * string a is lexicographically smaller than a string b if either of the
following is true: The first letter where they differ is smaller in a than in b.
    There is no index i such that a[i] != b[i] and a.length < b.length.
 *
 * Intuition: This is actually a graph problem as one character will point to
the next character and we also can observe
 * this is a topological sort graph, as a character must comes after another
character Detect if there is any contradiction in the ordering rules, such as a
cycle in the graph which would make it impossible to determine the order, or an
improper ordering like a word being a prefix of a previous word but appearing
later in the list. Assuming the ordering rules do not contain contradictions,
perform a topological sort on the graph to find the alien language character
order. If we can complete the topological sort with all characters accounted
for, we have successfully identified a possible alien language order. Otherwise,
we return an empty string.
 * */
class Solution {
public:
  std::string foreignDictionary(std::vector<std::string> &words) {

    // graph
    std::unordered_map<char, std::unordered_set<char>> graph;
    std::unordered_map<char, int> inDegree;

    // initialize the graph
    for (const std::string &word : words)
      for (const char &ch : word) {
        graph[ch] = std::unordered_set<char>();
        inDegree[ch] = 0;
      }

    // character seen so for
    int numCharacters{};
    int wordCount(words.size());

    // Building the graph
    for (int i{}; i < wordCount - 1; i++) {
      std::string currentWord{words[i]}, nextWord{words[i + 1]};
      int minLen = std::min(currentWord.length(), nextWord.length());

      // nextWord cannot be the prefix of the currentWord
      if (currentWord.length() > nextWord.length() &&
          currentWord.substr(0, minLen) == nextWord.substr(0, minLen))
        return "";

      for (int j{}; j < minLen; j++)
        if (currentWord[j] != nextWord[j]) {
          if (!graph[currentWord[j]].count(nextWord[j])) {
            graph[currentWord[j]].insert(nextWord[j]);
            inDegree[nextWord[j]]++;
          }
          break;
        }
    }

    // only push those with 0 indegree because they are the starting character
    // in the dictionary
    std::deque<char> q;
    for (auto &[ch, deg] : inDegree)
      if (deg == 0)
        q.emplace_back(ch);

    std::string ans{};
    while (!q.empty()) {
      char currentChar = q.front();
      q.pop_front();

      ans += currentChar;

      for (char neighbourChar : graph[currentChar])
        if (--inDegree[neighbourChar] == 0)
          q.emplace_back(neighbourChar);
    }

    return ans.size() < inDegree.size() ? "" : ans;
  }
};
