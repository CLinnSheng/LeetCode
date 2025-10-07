#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
/*
 * Initially all the lakes are empty but when it rains over the nth lake, the nth lake becomes full. If it rains overs a
 * lake that is full of water, then it will flood
 * Goal: Avoid any floods in any lake. Returns an array where ans[i] == -1 if rains[i] > 0 otherwise ans[i] is the lake
 * you choose to dry in the ith day if rains[i] == 0
 *
 * Intuition:
 * We can have a hashmap that store the day where it can dry the lake. And also a hashmap that store the day where the
 * lake is full
 * Time Complexity: O(nlgn)
 * */
class Solution
{
  public:
    std::vector<int> avoidFlood(std::vector<int> &rains)
    {
        int n(rains.size());
        std::vector<int> answer(n, 1);
        std::set<int> sunny_day;
        std::unordered_map<int, int> lakeFullDay;

        for (int i{}; i < n; i++)
        {
            // Sunny day
            // So in answer we need to decide which lake to dry ans[i]
            if (rains[i] == 0)
            {
                sunny_day.insert(i);
            }
            else
            {
                // Not sunny_day therefor ans[i] = -1
                answer[i] = -1;

                // Then proceed to check is there any possible way to dry this lake or does it flood the particular lake
                // or not
                if (lakeFullDay.count(rains[i]))
                {
                    // Get the first sunny day
                    auto it = sunny_day.lower_bound(lakeFullDay[rains[i]]);

                    // We flood the lake
                    if (it == sunny_day.end())
                        return {};

                    // Update the ans at the index where the day is sunny and the value will be the lake that dry
                    answer[*it] = rains[i];
                    sunny_day.erase(it);
                }
                lakeFullDay[rains[i]] = i;
            }
        }
        return answer;
    }
};
