/*
 * Stores the key with the value at the given the timestamp --> Stored in a hashmp
 * Get method, recent the most recent value of the key if set was previously called
 * and the most recent timestamp for that key [prev_timestamp <= timestamp]
 * */
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using std::string;

class TimeMap
{
    std::unordered_map<string, std::vector<std::pair<string, int>>> mp;

  public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back(std::make_pair(value, timestamp));
    }

    string get(string key, int timestamp)
    {
        // First check whether this key exist or not
        if (mp.count(key) == 0)
        {
            return "";
        }

        const std::vector<std::pair<string, int>> &vec = mp.at(key);
        int size = vec.size();

        // Use binary search instead of linear search
        int left{}, right{size - 1};
        string res = "";

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (vec[middle].second == timestamp)
            {
                return vec[middle].first;
            }
            else if (vec[middle].second <= timestamp)
            {
                res = vec[middle].first;
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        return res;
    }
};
