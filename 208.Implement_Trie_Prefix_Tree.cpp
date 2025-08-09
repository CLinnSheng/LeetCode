#include <algorithm>
#include <array>
#include <memory>
#include <string>

/*
 * Goal: Create a prefix tree class
 *
 * Intuition:
 * We can think of create a data structure wheere we can easily perform all the operations below
 * So the data structure will be a tree that linking all the words with the same prefix. For eg:
 * hot and hot dog. The tree will be h -> o -> t -> d -> o -> g So basically it will link at the back instead of having
 * another tree. We can have a flag to flag at t to tell us that this word exist
 * Time Complexity: O(m * n) --> all characters
 * */
using std::string;
struct TrieNode
{
    std::array<std::shared_ptr<TrieNode>, 26> alphabets;
    bool isWord{};

    TrieNode() : isWord{false}
    {
        std::fill(alphabets.begin(), alphabets.end(), nullptr);
    }
};

class PrefixTree
{
    std::shared_ptr<TrieNode> root;

  public:
    PrefixTree()
    {
        root = std::make_shared<TrieNode>();
    }

    void insert(string word)
    {
        auto temp{root};
        for (const auto &c : word)
        {
            if (temp->alphabets[c - 'a'] == nullptr)
                temp->alphabets[c - 'a'] = std::make_shared<TrieNode>();

            temp = temp->alphabets[c - 'a'];
        }

        // Mark it as a word
        temp->isWord = true;
    }

    bool search(string word)
    {
        auto temp{root};

        for (const auto &c : word)
        {
            if (temp->alphabets[c - 'a'] == nullptr)
                return false;
            temp = temp->alphabets[c - 'a'];
        }

        return temp->isWord;
    }

    bool startsWith(string prefix)
    {
        auto temp{root};

        for (const auto &c : prefix)
        {
            if (temp->alphabets[c - 'a'] == nullptr)
                return false;
            temp = temp->alphabets[c - 'a'];
        }

        return true;
    }
};
