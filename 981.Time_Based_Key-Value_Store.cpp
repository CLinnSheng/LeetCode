#include <string>
#include <vector>
#include <unordered_map>

/*
Goal: design a time based key value data structure that can store multiple values
for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Intuition: We try to find a data structure that are able to store the timestamp (vector)
Do binary saerch in the vector for the particular key
Take note that the timestamp is increasing in time (which means the seocnd input has to be larger than the first input)
We need some tweak on the binary search as it doesnt contain required the requested timestamp, we have to return the latest & closest timestamp (timestamp_prev <= timestamp)
*/

class TimeMap 
{
public:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> storage{};
    
    TimeMap() { }    
    void set(std::string key, std::string value, int timestamp) 
    {
        storage[key].emplace_back(timestamp, value);
    }
    
    std::string get(std::string key, int timestamp) 
    {
    
        auto& arrays = storage[key];
        std::string res = "";
        
        int left = 0, right = arrays.size();
        
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            
            if (arrays[middle].first > timestamp)
                right = middle - 1;
            else
            {
                res = arrays[middle].second;
                left = middle + 1;
            }
        }
        
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */