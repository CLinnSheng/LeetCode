/*
Goal: Built a LRU Cache that are able to return the value of key and insert new key into it
Constarint: If the key that we trying to insert exists, we replace the value of they. Otherwise, add the key-value into the cache.
** If the nubmer of key exceeds the capcity from this operation, evict the least recently used key.
Get & Put time complexity should be O(1)

Intuition: We need to keep track of the least recently used key for us to remove it when we trying to add new key if the capacity is max
Since need to get the value of the key --> Hashmap data structure
Since need to know the order of th key-value --> LinkedList data struture

The hashmap will have the key-value pair where the value is pointer that point to the specific node which stores the value in the linked list
Linkedlist will just basically store all the value in nodes and to keep track of the order of execution for easy access to the LEAST use node
*/
#include <list>
#include <unordered_map>
class LRUCache 
{
public:
    int capacity = 0;
    std::list<std::pair<int, int>> DLL;
    std::unordered_map<int, std::list<std::pair<int, int>> :: iterator> mp;
    LRUCache(int capacity) : capacity{ capacity }
    { }
    
    int get(int key) 
    {
        auto ptr = mp.find(key);
        
        // if no such key return -1
        if (ptr == mp.end()) return -1;
        
        // if found this key we needed to update the linkedlist as this key just got access
        // so we need to update the order
        // Order: recently used ---> least recently used (front --> back)
        
        // moved this node to the front
        DLL.splice(DLL.begin(), DLL, ptr->second);
        
        return ptr->second->second;
    }
    
    void put(int key, int value) 
    {
        auto ptr = mp.find(key);
        
        // if the key exists in the linked list
        // update the value
        if (ptr != mp.end())
        {
            ptr->second->second = value;
            DLL.splice(DLL.begin(), DLL, ptr->second);
            return;
        }
        
        // If the key didnt exists then will insert it into the LL
        // but we need to check the capcity first
        // if exceed we delete the least used key first then only insert
        if (mp.size() == capacity)
        {
            auto deleted_key = DLL.back().first;
            DLL.pop_back();
            mp.erase(deleted_key);
        }
        
        // Insert the new key-value pair
        DLL.emplace_front(key, value);
        mp[key] = DLL.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */