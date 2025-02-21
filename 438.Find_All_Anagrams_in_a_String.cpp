#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::vector;

/*
 * Goal: Return an array of all the start indices of p's anagrams in s. Can be in any order
 * anagrams: a string formed by rearranging the letters
 *
 * Intuitoin:
 * First how do we check anagrams? the easiest way is by using a hash map to store all the characters of anagrams.
 * So when the set is empty means all are matched.
 * The brute force way of solving it is by using double loop by checking every single possible window size of length p.
 * Time Complexity: O(n^2)
 *
 * If we observe from the naive approach, ew can see there are actually overlapping everytime we check. So is there any
 * way without checking the overlapping characters? yes by using a sliding window. we move the left pointer whenever
 * reach the required window size. This reduced the time complexity to O(n)
 * */
class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> answer;
        std::unordered_map<char, int> charSet;
        for (const auto &c : s)
            charSet[c]++;

        int left{}, right{};
        int len(s.length()), cnt(charSet.size());

        while (right < len)
        {
            // every move we will keep moving the right pointer
            // so check the element of the right pointer pointing at
            if (charSet.find(s[right]) != charSet.end())
            {
                charSet[s[right]]--;

                if (charSet[s[right]] == 0)
                    cnt--;
            }

            // Check whether is it the correct window size
            // if correct we add it if is a anagram
            if (right - left + 1 == p.length())
            {
                if (cnt == 0)
                    answer.emplace_back(left);

                // only add back if it belongs to p
                if (charSet.find(s[left]) != charSet.end())
                {
                    charSet[s[left]]++;
                    if (charSet[s[left]] == 1)
                        cnt++;
                }

                left++;
            }
            right++;
        }
        return answer;
    }
};
