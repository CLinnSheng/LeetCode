#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
/*
 * Return the minimum number of extra characters left over if break up S optimally
 * Problme here is how can we break up S optimally? Brute force way will be trying all possible way of breaking up the S
 * Store the dicitionary in a set
 * Time Complexity:
 * Each index of the string is computed once O(n), and for each function it iterate thorugh the string and created
 * substring here is O(n^2) Hence, O(n^3)
 *
 * Can we further optimize it? Do we really need to create substr which cost O(n) while iterate thorugh the str?
 * How can i check whether the substr exist without creating it? From here we can think of using a Trie Structure
 * */

struct TrieNode
{
    std::array<std::shared_ptr<TrieNode>, 26> children;
    bool isWord{};

    TrieNode() : isWord(false)
    {
        std::fill(children.begin(), children.end(), nullptr);
    }
};

struct TrieTree
{
    std::shared_ptr<TrieNode> root;

    TrieTree()
    {
        root = std::make_shared<TrieNode>();
    }

    void insert(const std::string &str)
    {
        auto currNode = root;

        for (const auto ch : str)
        {
            if (currNode->children[ch - 'a'] == nullptr)
            {
                currNode->children[ch - 'a'] = std::make_shared<TrieNode>();
            }

            currNode = currNode->children[ch - 'a'];
        }

        currNode->isWord = true;
    }
};

class Solution
{
  private:
    std::unordered_map<int, int> cache;
    std::unordered_set<std::string> set;
    std::shared_ptr<TrieTree> tree;

    int solution_1(const std::string &s, const int index)
    {
        // We can further optimize it because if you notice we keep calling this function with the same index

        // Base Case
        if (index == s.length())
        {
            return 0;
        }

        if (cache.find(index) != cache.end())
        {
            return cache[index];
        }

        // Skipping this character
        int ans = 1 + solution_1(s, index + 1);

        // O(n)
        for (int i{index}; i < s.length(); i++)
        {
            // O(n)
            auto subStr = s.substr(index, i - index + 1);

            if (set.find(subStr) != set.end())
            {
                // Split over here
                ans = std::min(ans, solution_1(s, i + 1));
            }
        }

        return cache[index] = ans;
    }

    int solution_2(const std::string &s, const int index)
    {
        // We can further optimize it because if you notice we keep calling this function with the same index

        // Base Case
        if (index == s.length())
        {
            return 0;
        }

        if (cache.find(index) != cache.end())
        {
            return cache[index];
        }

        // Skipping this character
        int ans = 1 + solution_2(s, index + 1);

        auto currNode = tree->root;

        // O(n)
        for (int i{index}; i < s.length(); i++)
        {
            if (currNode->children[s[i] - 'a'] == nullptr)
            {
                break;
            }

            currNode = currNode->children[s[i] - 'a'];

            if (currNode->isWord)
            {
                // Split over here
                ans = std::min(ans, solution_2(s, i + 1));
            }
        }

        return cache[index] = ans;
    }

  public:
    int minExtraChar(std::string s, std::vector<std::string> &dictionary)
    {
        // this->set = std::unordered_set<std::string>(dictionary.begin(), dictionary.end());
        // return solution_1(s, 0);
        this->tree = std::make_shared<TrieTree>();
        for (const auto word : dictionary)
        {
            tree->insert(word);
        }

        return solution_2(s, 0);
    }
};
