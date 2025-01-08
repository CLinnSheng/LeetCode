#include <cstddef>
#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>
using ll = long long;

/*
 * Goal: Return the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix.
 * The question is the same as the first version but this 1 need to be optimize
 *
 * Intuition:
 * We can use tries data structure because of checking prefix & suffix as we dont have to iterate through the string.
 * We will be saving the characters in a tree (which we call tries data structure), so for checking we just need to
 * traverse through the tree. Do we really need 2 tries data structure for each prefix & suffix? Can we find a way to
 * combine it? The way to combine is save the characters in pair for every node in the tries tree. Example: ababa we
 * save it in this way (a, a) -> (b, b) -> (a, a) -> (b, b) -> (a, a) the first element indicate the character moving to
 * the right direction and the other 1 in the opposite direction. Each nodes hold a count also We will build the tree in
 * the reverse order of the array words because we want to make sure the index pairs (i, j) such that i < j. get the
 * count first & then only add into the tree
 * */

struct pairHash
{
    template <typename T1, typename T2> std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

class TriesTree
{
  private:
    struct Node
    {
        std::unordered_map<std::pair<char, char>, std::shared_ptr<Node>, pairHash> children;
        int count{};
    };
    std::shared_ptr<Node> root{};

  public:
    TriesTree() : root{std::make_shared<Node>()}
    {
    }

    const int getCount(const std::string_view &s) const
    {
        int len(s.length());
        auto temp{root};

        for (int i{}; i < len; i++)
        {
            std::pair<char, char> node{std::make_pair(s[i], s[len - 1 - i])};

            if (temp->children.find(node) == temp->children.end())
                return 0;

            temp = temp->children[node];
        }
        return temp->count;
    }

    void addNode(const std::string_view &s)
    {
        int len(s.length());
        auto temp{root};

        for (int i{}; i < len; i++)
        {
            std::pair<char, char> node{std::make_pair(s[i], s[len - 1 - i])};
            // check whether we have inserted this node or not
            // node format: (s[0], s[len - 1])
            if (temp->children.find(node) == temp->children.end())
                temp->children[node] = std::make_shared<Node>();

            temp = temp->children[node];
            temp->count++;
        }
    }
};
class Solution
{
  public:
    ll countPrefixSuffixPairs(std::vector<std::string> &words)
    {
        ll answer{};
        std::shared_ptr<TriesTree> tree{std::make_shared<TriesTree>()};

        for (int i(words.size() - 1); i >= 0; i--)
        {
            answer += tree->getCount(words[i]);
            tree->addNode(words[i]);
        }
        return answer;
    };
};
