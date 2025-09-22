#include <unordered_map>
#include <vector>
/*
 * Intuition: Just use a hash map to store the frequency of each element.
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int maxFrequencyElements(std::vector<int> &nums)
    {
        std::unordered_map<int, int> freq;
        for (const auto num : nums)
            freq[num]++;

        int maxFreq{};
        for (const auto &[_, cnt] : freq)
            maxFreq = std::max(maxFreq, cnt);

        int answer{};

        for (const auto &[num, cnt] : freq)
            if (cnt == maxFreq)
                answer += maxFreq;

        return answer;
    }
};
