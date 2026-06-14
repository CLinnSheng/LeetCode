#include <algorithm>
#include <array>
#include <memory>
#include <string>

/*
 * Brute force way is storing all the words in a list. Then just check through the list
 * This will take O(m*n) where we iterate through the list then linearly scan through each string
 * How can we optimize it? We can make it to O(n) by using trie structure. Since trie structure linked through the
 * alphabet and has a flag to check whether the current node as the last character is it a word or not
 * And also over here we need to take care of wildcard '.' where it can be any letter
 * */

struct Trie
{
    std::array<std::shared_ptr<Trie>, 26> children;
    bool isWord{};

    Trie()
    {
        std::fill(children.begin(), children.end(), nullptr);
    }
};

class WordDictionary
{
  private:
    std::shared_ptr<Trie> root;

    bool dfs(const int index, const std::string &word, std::shared_ptr<Trie> node)
    {
        if (index == word.length())
        {
            return node->isWord;
        }

        // Check through each letter and find all possible path when we encounter '.'
        for (int i{index}; i < word.length(); i++)
        {
            if (word[i] != '.')
            {
                // Handle if the word is not register
                if (node->children[word[i] - 'a'] == nullptr)
                {
                    return false;
                }

                // Continue search
                node = node->children[word[i] - 'a'];
            }
            else
            {
                // Search all possible path
                for (const auto &child : node->children)
                {
                    if (child != nullptr && dfs(i + 1, word, child))
                    {
                        return true;
                    }
                }

                // Handle when all of the children also couldnt find the word
                return false;
            }
        }

        return node->isWord;
    }

  public:
    WordDictionary()
    {
        root = std::make_shared<Trie>();
    }

    void addWord(std::string word)
    {
        auto currNode = root;

        for (const auto ch : word)
        {
            if (currNode->children[ch - 'a'] == nullptr)
            {
                currNode->children[ch - 'a'] = std::make_shared<Trie>();
            }

            currNode = currNode->children[ch - 'a'];
        }

        currNode->isWord = true;
    }

    bool search(std::string word)
    {
        return dfs(0, word, root);
    }
};
