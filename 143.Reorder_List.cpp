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
    void reorderList(ListNode *head)
    {
        // Reorder the LL into a specific order
        // The order is just simply alternate element from both the front and end
        // Just simply store all the nodes into an array and reconstruct

        if (head == nullptr)
        {
            return;
        }

        // Store the nodes
        ListNode *temp = head;
        std::vector<ListNode *> nodes;
        while (temp)
        {
            nodes.push_back(temp);
            temp = temp->next;
        }

        // Reconstruct the LL
        std::vector<ListNode *> new_order;
        int left{}, right(nodes.size() - 1);

        while (left <= right)
        {
            if (left == right)
            {
                new_order.push_back(nodes[left]);
                break;
            }

            new_order.push_back(nodes[left++]);
            new_order.push_back(nodes[right--]);
        }

        for (int i{1}; i < new_order.size(); i++)
        {
            head->next = new_order[i];
            head = head->next;
        }

        head->next = nullptr;
    }
};
