#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Given a string s & a dictionary of words dictionary. Break s into one or more non-empty overlapping substrings such
 * taht each substring is present in dictionary There may be some extra characters in s which is not present in the
 * dictionary
 *
 * Goal: Return the minimum number of extra characters left over after breakking up S optimally
 *
 * Intuition:
 * We need to break s optimally such that it will has lesser extra character
 * One important thing is that we can actually skip character while breaking up the s.
 *
 * So for brute force
 * We will just have to try every single substring from length of 1
 * We can use a hash set to store the words so we can access it in O(1)
 * We can optimize it by caching because we repeatedly solving the same subproblem multiple time
 * Time Complexity: O(n^3)
 *
 * We can actually further optimize it at the substr over there.
 * If you notice current caching method, it will have to keep check for every substr. Why not we use the first character
 * as a determination point? By checking through the prefix? So we can straight away break if the first few characters
 * is not in our data structure
 * eg: [leet, code, leetcode]. s = "abcasdsdsdsds". Since a is not in the prefix of any words so we can skip the
 * character
 * */

struct TrieNode
{
    std::unordered_map<int, TrieNode *> alphabets;
    bool isWord;

    TrieNode() : isWord(false)
    {
    }
};

struct TrieTree
{
    TrieNode *root;
    TrieTree(const std::vector<std::string> &words)
    {
        root = new TrieNode();

        for (const auto &word : words)
        {
            auto temp{root};
            for (const auto &ch : word)
            {
                if (temp->alphabets.find(ch - 'a') == temp->alphabets.end())
                    temp->alphabets[ch - 'a'] = new TrieNode();

                temp = temp->alphabets[ch - 'a'];
            }

            temp->isWord = true;
        }
    }
};

class Solution
{
  private:
    std::unordered_map<int, int> cache;
    TrieTree *tree;

    // O(n)
    int bruteForce(const int &index, const std::string &s, const std::unordered_set<std::string> &sets)
    {
        // Base Case
        if (index == s.length())
            return 0;

        if (cache.count(index))
            return cache[index];

        // Trying out every single substring from length of 1, skipping this character
        int ans = 1 + bruteForce(index + 1, s, sets);

        for (int i{index}; i < s.length(); i++) // O(n)
        {
            // if this substring exists, then dfs on the next index
            if (sets.count(s.substr(index, i - index + 1))) // O(n)
                ans = std::min(ans, bruteForce(i + 1, s, sets));
        }

        return cache[index] = ans;
    }

    int dfs_trie(const int &index, const std::string &s)
    {
        // Base Case
        if (index == s.length())
            return 0;

        if (cache.count(index))
            return cache[index];

        // Trying out every single substring from length of 1, skipping this character
        int ans = 1 + dfs_trie(index + 1, s);
        TrieNode *currNode = tree->root;

        for (int i{index}; i < s.length(); i++) // O(n)
        {
            if (currNode->alphabets.find(s[i] - 'a') == currNode->alphabets.end())
                break;

            currNode = currNode->alphabets[s[i] - 'a'];

            if (currNode->isWord)
                ans = std::min(ans, dfs_trie(i + 1, s));
        }

        return cache[index] = ans;
    }

  public:
    int minExtraChar(std::string s, std::vector<std::string> &dictionary)
    {
        // Caching: O(n^3)
        // std::unordered_set<std::string> sets(dictionary.begin(), dictionary.end());
        // return bruteForce(0, s, sets);

        tree = new TrieTree(dictionary);
        return dfs_trie(0, s);
    }
};
