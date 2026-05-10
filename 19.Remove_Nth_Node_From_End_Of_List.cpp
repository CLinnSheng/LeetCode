/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Quite straight forward question
        // But we need to handle edge cases
        // What if the node is the first element?
        // What if the node is the last element?

        // First we keep all the nodes in an array
        // So we can access any of the nodes in the LL easily
        std::vector<ListNode *> nodes;
        ListNode *temp = head;
        while (temp)
        {
            nodes.push_back(temp);
            temp = temp->next;
        }

        // Now we find the node we want to remove
        int size = nodes.size();
        int index = size - n;

        // First index
        if (index == 0)
        {
            return head->next;
        }

        // Last index
        if (index == size - 1)
        {
            nodes[size - 2]->next = nullptr;
            return head;
        }

        // In between, jsut reconnect the nodes
        ListNode *prev = nodes[index - 1];
        ListNode *next = nodes[index + 1];
        prev->next = next;

        return head;
    }
};
