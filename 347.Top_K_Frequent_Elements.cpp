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
class Solution
{
  private:
    struct Comparator
    {
        bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b)
        {
            return a.second < b.second;
        }
    };

  public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::vector<int> answer;

        std::unordered_map<int, int> num_freq;
        for (const int &num : nums)
            num_freq[num]++;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> pq;

        for (const auto &[val, freq] : num_freq)
            pq.push({val, freq});

        while (k > 0)
        {
            auto top{pq.top()};
            pq.pop();

            answer.emplace_back(top.first);
            k--;
        }
        return answer;
    }
};
