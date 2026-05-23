/*
 * Design LFU Cache
 *
 * Problem:
 * Need a cache that evicts the least frequently used key when capacity is full
 * - So from here we know that the frequency of each key is matter, and we need some way to easily acces and store the
 * frequency
 * - Things need to take care of
 *  - value of each key
 *  - frequency of each key
 *  - LRU key --> We can group keys by its frequency and store it in a LinkedList way so that we know the back is always
 * the LRU
 *
 * Edge Case:
 * What if 2 key having the same frequency and we need to remove one?
 * - Remove the least recently used
 *
 * Data Structure:
 * - keyVal  : key -> value          (O(1) value lookup)
 * - keyFreq : key -> frequency      (O(1) know which freq bucket this key belongs to)
 * - freqLL  : frequency -> LinkedList of keys at that frequency
 *             Why LinkedList? we need LRU ordering within each bucket --> O(1) insert at head, O(1) remove from tail
 *             Why hashmap inside LinkedList? arbitrary node removal is O(n) without it --> pair with nodes map for O(1)
 *             Why freqLL as hashmap not array? frequency has no upper bound, hashmap grows dynamically
 * - minFreq : current minimum frequency
 *             Can easily know which freqLL to evict from, in O()
 * */

#include <cstddef>
#include <unordered_map>
struct Node
{
    Node *prev;
    Node *next;
    int val;

    Node(int val = 0, Node *prev = nullptr, Node *next = nullptr) : val(val), prev(prev), next{next}
    {
    }
};

// Doubly Linked List representing one frequency bucket
// - left sentinel : dummy head, most recent side
// - right sentinel: dummy tail, least recent side
// - nodes map     : key -> Node* for O(1) arbitrary removal
// Invariant: keys ordered left to right from most to least recently used
struct LinkedList
{
    // Boundary pointer so can easily access the front and the end
    Node *left;
    Node *right;
    // O(1) access of the node
    std::unordered_map<int, Node *> nodes;

    /*
     * A few helper method that we need over here
     * - Removing the specific node
     * - Pushing in the front/left
     * - Popping from the back/right
     * - Size of LL
     * */
    LinkedList()
    {
        left = new Node();
        right = new Node();
        left->next = right;
        right->prev = left;
    }

    ~LinkedList()
    {
        Node *curr = left;
        while (curr != nullptr)
        {
            Node *temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

    size_t size()
    {
        return nodes.size();
    }

    // Removing the specific node
    // Why we need this? because if we replace this key or access it we need to increase its count, so it no longer
    // belong to this freq LL
    void pop(int key)
    {
        // Finding the node
        // Remove it
        if (nodes.find(key) != nodes.end())
        {
            // Get the node
            Node *node = nodes[key];

            // Remove the node and reconnecting the LL
            Node *prev_node = node->prev;
            Node *next_node = node->next;

            prev_node->next = next_node;
            next_node->prev = prev_node;

            nodes.erase(key);
            delete node;
        }
    }

    // Helper method to insert new into the LL
    void pushLeft(int key)
    {
        Node *node = new Node(key);

        // Insert into LL
        Node *next_node = left->next;

        node->next = next_node;
        node->prev = left;

        left->next = node;
        next_node->prev = node;

        nodes[key] = node;
    }

    // Pop the least recently used nodes from the LL
    // Return the key of the node
    int popRight()
    {
        int key = right->prev->val;

        // Reuse the pop method
        pop(key);

        return key;
    }
};
class LFUCache
{
    int capacity;
    int minFreq;                                  // Tracking the current min freq
    std::unordered_map<int, int> keyVal;          // Getting the value if exist
    std::unordered_map<int, int> keyFreq;         // Mapping the key to the freq of the LL it belongs
    std::unordered_map<int, LinkedList *> freqLL; // Mapping the frequency of each LL

  public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0)
    {
        freqLL[0] = new LinkedList();
    }

    int get(int key)
    {
        // Check whether the node exist or not
        if (keyVal.find(key) == keyVal.end())
        {
            return -1;
        }

        // Key found increment its frequency and return the value
        updateFreq(key);
        return keyVal[key];
    }

    /*
     * Upate the value of the key if present, or insert the key if not present
     * When reach capacity, it should replace the least frequently used
     * */
    void put(int key, int value)
    {
        // Base Case
        if (capacity == 0)
        {
            return;
        }

        // 3 Cases:
        // 1. Existing key --> update value and frequency
        // 2. New key, at capacity --> evict LFU node first, then insert
        // 3. New key, under capacity --> insert directly

        // First we check the capacity first if max then we remove the LFU node
        if (keyVal.size() == capacity && keyVal.find(key) == keyVal.end())
        {
            int removeNode_key = freqLL[minFreq]->popRight();

            // Remove the node first from the cache
            keyVal.erase(removeNode_key);
            keyFreq.erase(removeNode_key);
        }

        // Inserting the new node
        // Updating the cache
        keyVal[key] = value;

        // New key always starts at freq 0 temporarily
        // Reset minFreq to 0 so updateLFUCache correctly moves it to freqLL[1] and sets minFreq = 1
        if (keyFreq.find(key) == keyFreq.end())
        {
            minFreq = 0;
            freqLL[0]->pushLeft(key);
            keyFreq[key] = 0;
        }

        updateFreq(key);
    }

    // Increments the frequency of a key:
    // 1. Remove key from its current freq bucket
    // 2. Insert into the next freq bucket (cnt + 1)
    // 3. If the old bucket is now empty and was the minFreq bucket, increment minFreq
    void updateFreq(int key)
    {
        // Get the original count then increase it
        int cnt = keyFreq[key];

        keyFreq[key]++;
        // Remove from the current freq bucket and add it into cnt + 1 freq bucket
        freqLL[cnt]->pop(key);

        // Check whether is it a new linkedlist or not
        if (freqLL.find(cnt + 1) == freqLL.end())
        {
            freqLL[cnt + 1] = new LinkedList();
        }

        freqLL[cnt + 1]->pushLeft(key);

        // Updating the LFUCount
        // IMPORTANT need to check whether the linkedlist of the current minFreq  is empty or not
        if (cnt == minFreq && freqLL[cnt]->size() == 0)
        {
            this->minFreq++;
        }
    }
};
