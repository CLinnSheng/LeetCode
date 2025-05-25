#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Given an array of strings, words. Each element of words consists of two lowercase ltter only
 * Create the longest possible palindrome by selecting some elements from words and concatenating
 * them in any order. Each element can be selected at most once.
 *
 * Goal: Return the length of the longest palindrome that can create. otherwise create any palindrome, return 0.
 *
 * Intuition:
 * There can be 2 type of word, one is already palindrome which is consists of the same letter
 * while another 1 consists of different letter.
 * So for word consists of the same letter, we will always include it no matter what because the string
 * will always be palindrome but for another 1 we need a pair of it.
 * So im thinking of using a hash map to store the frequency of each string.
 * Then we will iterate through the map again, find whether the reverse of it exists or not.
 * If exists take the min, whether is it odd or even dont matter.
 * Odd or even matters for string with the same letter only.
 * We consider all has even number 1, and then for odd only take one
 * Time Complexity: O(n)
 *
 * */
class Solution
{
  public:
    int longestPalindrome(std::vector<std::string> &words)
    {
        int len{};
        std::unordered_map<std::string, int> map;
        bool pair{false};

        for (auto word : words)
            map[word]++;

        bool odd{false};
        std::unordered_map<std::string, int>::iterator it{map.begin()};
        while (it != map.end())
        {
            std::string str{it->first};
            int freq{it->second};

            if (str[0] == str[1])
            {
                len += (freq / 2) * 4;
                if (freq % 2)
                    odd = true;
            }
            else
            {
                std::string reverse(str);
                std::reverse(reverse.begin(), reverse.end());

                auto reverse_it = map.find(reverse);
                if (reverse_it != map.end())
                {
                    len += (std::min(freq, reverse_it->second) * 4);
                    map.erase(reverse_it);
                }
            }
            it = map.erase(it);
        }
        return len + odd * 2;
    }
};
