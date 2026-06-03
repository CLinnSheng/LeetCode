#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

/*
 * Happy string if
 * i. only contains 'a', 'b', 'c'
 * ii. no 'aaa', 'bbb', 'ccc' as substring
 * iii. at most a occurence of the letter 'a' and the same for 'b' and 'c'
 *
 *
 * Freq of each char matter --> Hashmap
 * Then how do we construct the string while still making sure we dont break the aaa substring kind of thing
 * We should be greedy to always choose the 1 with the most freq, so that in the end we dont stuck with just one element
 * which eventually will cause the triple occurence substring
 * So store in a maxHeap
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
    std::string longestDiverseString(int a, int b, int c)
    {
        // Populate the map
        std::unordered_map<char, int> map;
        map['a'] = a;
        map['b'] = b;
        map['c'] = c;

        std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, Comparator> maxHeap;
        for (const auto &[ch, freq] : map)
        {
            if (freq != 0)
            {
                maxHeap.emplace(ch, freq);
            }
        }

        std::string ans;
        while (maxHeap.size())
        {
            auto top = maxHeap.top();
            maxHeap.pop();

            // Before pushing it checking whether we have 2 repeating characters or not
            if (ans.length() < 2)
            {
                ans += top.first;
                top.second--;
            }
            else
            {
                int n = ans.size();
                if (ans[n - 1] == top.first && ans[n - 2] == top.first)
                {
                    if (maxHeap.empty())
                    {
                        return ans;
                    }
                    else
                    {
                        // Get the next element
                        auto temp = maxHeap.top();
                        maxHeap.pop();

                        ans += temp.first;
                        temp.second--;

                        if (temp.second > 0)
                        {
                            maxHeap.push(temp);
                        }
                    }
                }
                else
                {
                    ans += top.first;
                    top.second--;
                }
            }

            if (top.second > 0)
            {
                maxHeap.push(top);
            }
        }

        return ans;
    }
};
