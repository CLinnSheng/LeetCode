#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

/*
 * Goal: Return the k most frequent elements
 *
 * Intuition:
 * Important things is "k most frequent". We can use a priority queue and the queue is based on the number of element
 * for each integer. Time Complexity: O(nlgn)
 * */
struct Comparator
{
    bool operator()(const std::pair<int, int> &A, const std::pair<int, int> &B)
    {
        return A.second < B.second;
    }
};
class Solution
{
  public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        // // collect the freq of each char
        // std::unordered_map<int, int> freq;
        // for (const auto num : nums)
        // {
        //     freq[num]++;
        // }

        // // Most direct way is straight away use a max heap
        // // Push it into the heap
        // // O(nlgn)
        // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> maxHeap;
        // for (const auto &[num, cnt]: freq)
        // {
        //     maxHeap.push(std::make_pair(num, cnt));
        // }

        // std::vector<int> ans;
        // while (k)
        // {
        //     ans.push_back(maxHeap.top().first);
        //     maxHeap.pop();
        //     k--;
        // }

        // return ans;

        // We can further optimize it by jusing pure array instead of a priority queue/heap
        // Edge Case where the ans only contains 1 element for any value of k if the entire arrays contains the same
        // element We can have an array of freq with size of max possible freq where freq[i] = val i is the freq and val
        // is the value that contains i times in the array
        std::unordered_map<int, int> freq;
        for (const auto num : nums)
        {
            freq[num]++;
        }

        // the indices is the length and the value will just simply be val that has appear i times
        std::vector<std::vector<int>> freqArray(nums.size() + 1);
        for (const auto &[val, cnt] : freq)
        {
            freqArray[cnt].push_back(val);
        }

        // Start from the back
        std::vector<int> res;
        for (int i(freqArray.size() - 1); i >= 0; i--)
        {
            for (const auto val : freqArray[i])
            {
                if (k == 0)
                {
                    return res;
                }
                res.push_back(val);
                k--;
            }
        }
        return res;
    }
};
