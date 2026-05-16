/*
 * Put Method -> Update the value of the key if the key exists. Otherwise, add the key-value
 * pair to the cache. If exceed capacity remove the least recently used key
 *
 * So we need to always keep track of which key is the least recently used
 *
 * And each operation must be in O(1)
 *
 * Since we need each operation in O(1), a hashmap must be used so that we can easily get the value given the key
 * And also since the time where each key get access does matter, we can use LL because LL link all the nodes together
 * So our hashmap will just simply map the key to the node
 * */

#include <unordered_map>
struct Node
{
    Node *next;
    Node *prev;
    int key;
    int val;

    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr)
    {
    }
};

class LRUCache
{
    std::unordered_map<int, Node *> mp;
    // Have 2 nodes that act as boundary, so we can easily access the first and last element
    Node *left;
    Node *right;
    int capacity;

    void remove(Node *node)
    {
        // Then relink the LL
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;

        // Remove the node
        mp.erase(node->key);
        delete node;
    }

    void insert(int key, int val)
    {
        mp[key] = new Node(key, val);

        // Insert into the back of LL
        Node *prev = right->prev;
        prev->next = mp[key];
        mp[key]->next = right;
        mp[key]->prev = prev;
        right->prev = mp[key];
    }

  public:
    LRUCache(int capacity)
    {
        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
        this->capacity = capacity;
    }

    int get(int key)
    {
        // Definitely need to search from the map, so we can achieve O(1)
        // Update the node to be most recently used
        if (mp.find(key) != mp.end())
        {
            // Reorder the list so that this node is front or most recently used
            Node *node = mp[key];
            int _key = node->key, _val = node->val;

            // 1. Remove it from the LL
            remove(node);

            // 2. Insert it to the back of the LL
            insert(_key, _val);
            // actually can make it always insert at the back, because 'put' method will insert in the front
            // as well

            return mp[key]->val;
        }

        return -1;
    }

    void put(int key, int value)
    {
        // First Case: Existing Key
        if (mp.find(key) != mp.end())
        {
            // Update the value and move it to the back
            Node *node = mp[key];

            // Remove the node
            remove(node);

            // Update the map with the latest node and insert at the back
            insert(key, value);
            return;
        }

        // Second Case: No existing key but here need to take care of the size of the LL
        int size = mp.size();

        // 1. Enough Size
        if (size < capacity)
        {
            // Straight away insert
            insert(key, value);
        }
        else
        {
            // Remove the least recently used node
            Node *node = left->next;
            remove(node);

            // Insert the new node
            insert(key, value);
        }
    }
};
