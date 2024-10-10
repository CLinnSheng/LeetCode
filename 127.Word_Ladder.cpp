#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Transformation sequence from word beginWord to word endWord using a
 * dictionary wordList is a sequence of words beginWord -> s1 -> ... -> sk such
 * that every adjacent pair of words differs by a single letter Every si for 1
 * <= i <= k is in wordList. Note that the beginWord dont need to be in the
 * WordList. sk is the endWord
 *
 * Intuition:
 * Check whether the endWord is in the wordList or not
 * Since we can transform from 1 word to anotehr word provided that they
 * differes by a single letter We can treat every single node as a word in the
 * wordList. And hwo do we know which word should i connect to for the next
 * node. We can use a map data structure to map a paritcular pattern to all
 * possible words in the wordList for eg: h*t -> hot, hat, etc..
 * Time Complexity: O(m * n) where m is the number of word in the wordList & n
 * is the maximum number of charcters in a word Space Complexity: O(m * n)
 * */
class Solution {
public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string> &wordList) {

    if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
      return 0;

    wordList.emplace_back(beginWord);
    std::unordered_map<std::string, std::vector<std::string>> mapping;

    for (const auto &word : wordList) {
      for (int i = 0; i < word.length(); i++) {
        std::string possible_word =
            word.substr(0, i) + "#" + word.substr(i + 1);
        mapping[possible_word].emplace_back(word);
      }
    }

    int transformation = 1;
    // a set data structure to track the visited node in the graph
    std::unordered_set<std::string> visitedWord{beginWord};
    // can either use dfs or bfs to traverse the graph
    // here we use bfs
    std::deque<std::string> queue;
    queue.emplace_back(beginWord);

    // bfs
    while (!queue.empty()) {
      int curr_qSize = queue.size();

      for (int i = 0; i < curr_qSize; i++) {
        std::string currWord = queue.front();
        queue.pop_front();

        if (currWord == endWord)
          return transformation;

        // traverse every possible next word
        for (int j = 0; j < currWord.length(); j++) {
          std::string currWordPossible =
              currWord.substr(0, j) + "#" + currWord.substr(j + 1);

          for (const auto &neigh : mapping[currWordPossible])
            if (!visitedWord.count(neigh)) {
              visitedWord.insert(neigh);
              queue.emplace_back(neigh);
            }
        }
      }
      transformation++;
    }

    return 0;
  }
};
