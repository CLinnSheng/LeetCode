#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
/*
 * Reorganize the string so that no 2 adjacent characters are the same
 * Can be any possible arrangement
 *
 * So order doesnt matter, what we want to make sure is no 2 adjacents characters are the same
 * So first things is the freq of each char in the string matter. We need to priority those characters with more freq
 * Then is only possible to create the string otherwise we will just left with the same characters
 *
 * Store it in a hashmap first to track the freq of each char
 * Use a maxHeap, so we always pop the most character
 * But how do we handle after popping it and use it? Should we insert again into the heap?
 * But this will cause the next character to be the same if it happen to be the most freq again
 * We can have a variable to track the char that is in cooldown
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 * */

struct Comparator
{
    bool operator()(const std::pair<char, int> &A, const std::pair<char, int> &B)
    {
        return A.second < B.second;
    }
};

class Solution
{
  public:
    std::string reorganizeString(std::string s)
    {
        std::string ans;

        // Populate the map & insert into the heap
        std::unordered_map<char, int> mp;
        for (const auto ch : s)
        {
            mp[ch]++;
        }

        std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, Comparator> maxHeap;
        for (const auto &[ch, freq] : mp)
        {
            maxHeap.emplace(ch, freq);
        }

        std::pair<char, int> prev;

        while (ans.length() < s.length())
        {
            // Base Case
            // Where we have no element left in the heap and prev element still havent fin yet
            if (maxHeap.empty() && prev.second > 0)
            {
                return "";
            }

            // Getting the most freq char
            auto top = maxHeap.top();
            maxHeap.pop();

            ans += top.first;

            top.second--;

            // Push back the prev element if freq > 0
            if (prev.second > 0)
            {
                maxHeap.push(prev);
            }

            // Update the prev element
            prev = top;
        }

        return ans;
    }
};
