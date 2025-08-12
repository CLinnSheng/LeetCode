#include <algorithm>
#include <array>
#include <memory>
#include <string>
using std::string;

/*
 * Goal: Implement all data structure
 * search: return true if any string in the data structure that matches 'word'. 'word' may contain '.' where dots can be
 * matched with any letter
 *
 * Intuition:
 * We can use a trie tree data structure so we can easily store and search word with the same prefix
 * We just need to handle the search for the '.'. So we can use dfs to search through all possible combinations if
 * encounter '.' Time Complexity: O(m * n)
 *
 * */
struct TrieNode
{
    std::array<std::shared_ptr<TrieNode>, 26> alphabets;
    bool isWord;

    TrieNode() : isWord(false)
    {
        std::fill(alphabets.begin(), alphabets.end(), nullptr);
    }
};

class WordDictionary
{
  private:
    std::shared_ptr<TrieNode> root;

    bool dfs(const std::string &word, const int &index, std::shared_ptr<TrieNode> node)
    {
        auto currNode{node};

        for (int i{index}; i < word.length(); i++)
        {
            // not '.' then handle it like how we handle in trie data structure
            if (word[i] != '.')
            {
                if (currNode->alphabets[word[i] - 'a'] == nullptr)
                    return false;
                else
                    currNode = currNode->alphabets[word[i] - 'a'];
            }
            else
            {
                // '.', try all possible word because is a wildcard
                for (const auto &child : currNode->alphabets)
                {
                    if (child != nullptr && dfs(word, i + 1, child))
                        return true;
                }
                return false;
            }
        }
        return currNode->isWord;
    }

  public:
    WordDictionary()
    {
        root = std::make_shared<TrieNode>();
    }

    void addWord(string word)
    {
        auto temp{root};

        for (const auto &c : word)
        {
            if (temp->alphabets[c - 'a'] == nullptr)
                temp->alphabets[c - 'a'] = std::make_shared<TrieNode>();

            temp = temp->alphabets[c - 'a'];
        }

        temp->isWord = true;
    }

    bool search(string word)
    {
        return dfs(word, 0, root);
    }
};
