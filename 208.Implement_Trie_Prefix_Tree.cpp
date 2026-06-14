#include <algorithm>
#include <array>
#include <memory>
#include <string>

/*
 * Trie Structure is a tree-like data structure where each node contains a hashmap to store references to its child
 * nodes which represent characters. Each node also includes a boolean flag to indicate whether the current node marks
 * the end of a valid word
 *
 * Trie starts with a root node that does not hold any character and just serve as the entry point
 * Time Complexity: O(n)
 * Space Complexity: O(t)
 * t -> total number of node created
 * */

struct TrieStruct
{
    std::array<std::shared_ptr<TrieStruct>, 26> children;
    bool isWord{};

    TrieStruct()
    {
        std::fill(children.begin(), children.end(), nullptr);
    }
};

class PrefixTree
{
    std::shared_ptr<TrieStruct> root;

  public:
    PrefixTree()
    {
        root = std::make_shared<TrieStruct>();
    }

    // Iterate through the characters starting from the root node of the trie tree.
    // If word[i] is empty create a new node otherwise just continue point to it until end of the word and mark it as
    // boolean
    void insert(std::string word)
    {
        auto currNode = root;

        for (const auto ch : word)
        {
            // Check whether the node exist or not
            // Create it if not exist other continue iterate
            if (currNode->children[ch - 'a'] == nullptr)
            {
                currNode->children[ch - 'a'] = std::make_shared<TrieStruct>();
            }

            currNode = currNode->children[ch - 'a'];
        }

        // Mark it as word
        currNode->isWord = true;
    }

    // Almost same operation as insert check whether the node is nullptr or a valid node or not, then check its flag
    bool search(std::string word)
    {
        auto currNode = root;

        for (const auto ch : word)
        {
            if (currNode->children[ch - 'a'] == nullptr)
            {
                return false;
            }

            currNode = currNode->children[ch - 'a'];
        }

        return currNode->isWord;
    }

    bool startsWith(std::string prefix)
    {
        auto currNode = root;

        for (const auto ch : prefix)
        {
            if (currNode->children[ch - 'a'] == nullptr)
            {
                return false;
            }

            currNode = currNode->children[ch - 'a'];
        }

        return true;
    }
};
