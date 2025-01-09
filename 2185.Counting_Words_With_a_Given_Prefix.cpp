#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

/*
 * Goal: Return the number of strings in words that contain pref as the prefix
 *
 * Intuition:
 * Just iterate through the words array and check every single string wheher has the prefix pref
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 * Theres also another way is by using trie data structure
 * Where each nodes also hold the count.
 * So basically after we add all the nodes, then we will traverse the tree by using the pref and get the count at the
 * last character.
 * */

class TrieTree
{
  private:
    struct Node
    {
        // 26 character
        std::array<std::shared_ptr<Node>, 26> alphabets;
        int count{};
    };

    std::shared_ptr<Node> root{std::make_shared<Node>()};

  public:
    void add(const std::string_view &word, const int &len)
    {
        auto temp{root};

        for (int i{}; i < std::min((int)word.length(), len); i++)
        {
            int ch(word[i] - 'a');
            if (temp->alphabets[ch] == nullptr)
                temp->alphabets[ch] = std::make_shared<Node>();

            temp = temp->alphabets[ch];
            temp->count++;
        }
    }

    const int getCount(const std::string_view &pref) const
    {
        auto temp{root};

        for (int i{}; i < pref.length(); i++)
        {
            int ch(pref[i] - 'a');
            if (temp->alphabets[ch] == nullptr)
                return 0;
            temp = temp->alphabets[ch];
        }
        return temp->count;
    }
};

class Solution
{
  public:
    int prefixCount(std::vector<std::string> &words, std::string pref)
    {
        // int answer{};
        //
        // for (const auto &word : words)
        //     if (word.find(pref) == 0)
        //         answer++;
        //
        // return answer;

        std::shared_ptr<TrieTree> tree = std::make_shared<TrieTree>();
        for (const auto &word : words)
            tree->add(word, pref.length());

        return tree->getCount(pref);
    }
};
