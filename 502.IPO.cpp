#include <functional>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

/*
 * Pick a list of at most k project to maximize final capital
 * Initial capital w
 *
 * The order of project get executed is totally random so that means we can pick any of it anytime we want
 * So 2 thing to consider when we picking a project
 * First it bring the most net profit -> maxHeap
 * Second is within our capital capability --> minHeap
 * So just loop until the our capital cant start any project
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
            minCapital;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>>
            maxProfit;
        int cnt{};

        for (int i{}; i < profits.size(); i++)
        {
            minCapital.emplace(capital[i], i);
            // maxProfit.emplace(profits[i], i);
        }

        // So we find the most profittable project within the project we can afford
        while (cnt < k && (!minCapital.empty() || !maxProfit.empty()))
        {
            // Push all the projects into the max Heap
            while (!minCapital.empty() && minCapital.top().first <= w)
            {
                auto top = minCapital.top();
                minCapital.pop();

                maxProfit.emplace(profits[top.second], top.second);
            }

            // Base Case
            if (maxProfit.empty())
            {
                break;
            }

            // Take the most profitable project
            auto project = maxProfit.top();
            maxProfit.pop();
            w += project.first;
            cnt++;
        }

        return w;
    }
};
