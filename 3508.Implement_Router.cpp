#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
class Router
{
  public:
    typedef std::pair<int, std::pair<int, int>> pip;
    std::queue<pip> q;
    std::set<pip> ust;
    std::unordered_map<int, std::pair<int, std::vector<int>>> mp;
    int memoryLimit;
    Router(int memoryLimit)
    {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        if (ust.find({source, {destination, timestamp}}) != ust.end())
        {
            return false;
        }
        else
        {
            q.push({source, {destination, timestamp}});
            mp[destination].second.push_back(timestamp);

            ust.insert({source, {destination, timestamp}});
            if (q.size() > memoryLimit)
            {
                pip temp = q.front();
                q.pop();
                mp[temp.second.first].first++;
                ust.erase(temp);
            }
            return true;
        }
    }

    std::vector<int> forwardPacket()
    {
        std::vector<int> ans;
        if (!q.empty())
        {
            pip t = q.front();
            q.pop();
            mp[t.second.first].first++;
            ans.push_back(t.first);
            ans.push_back(t.second.first);
            ans.push_back(t.second.second);
            ust.erase(t);
        }
        return ans;
    }

    int getCount(int destination, int startTime, int endTime)
    {
        // WE use pos to determine where is the packet havent set yet instead of going to delete it
        int pos = mp[destination].first;
        return std::upper_bound(mp[destination].second.begin() + pos, mp[destination].second.end(), endTime) -
               lower_bound(mp[destination].second.begin() + pos, mp[destination].second.end(), startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
