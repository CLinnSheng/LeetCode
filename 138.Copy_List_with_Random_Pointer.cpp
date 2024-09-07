/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
Goal: Return a copied linked list without reference to the original list
Intuition: Since we have to keep track of every original node because we want to get the next & random node but at the same time cannot reference to the original node
so what we can do is have hash map that map the old node to the new node. So the next & random node of the new node can be connected by using the hashmap.
eg:
map: Key     Val
     OldNode NewNode
map[OldNode]->next = map[OldNode->next]; so the newnode next is map to the newnode not the old node
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        if (head == nullptr) return nullptr;

        std::unordered_map<Node*, Node*> mp;
        // Initialize a old new link to new node which is null to null
        // mp[nullptr] = nullptr;

        Node* old_node = head;
        while (old_node)
        {
            Node* new_node = new Node(old_node->val);
            mp[old_node] = new_node;
            old_node = old_node->next;
        }

        old_node = head;
        while (old_node)
        {
            mp[old_node]->next = mp[old_node->next];
            mp[old_node]->random = mp[old_node->random];
            old_node = old_node->next;
        }

        return mp[head];
    }
};