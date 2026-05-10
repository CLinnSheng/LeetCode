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

#include <unordered_map>
class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        // Just save the new node coresspond to the new node
        // Cannot direct construct while traverse through it because of need to setting the next field
        std::unordered_map<Node *, Node *> nodes;

        Node *temp = head;
        while (temp)
        {
            nodes[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp)
        {
            nodes[temp]->next = nodes[temp->next];
            nodes[temp]->random = nodes[temp->random];
            temp = temp->next;
        }

        return nodes[head];
    }
};
