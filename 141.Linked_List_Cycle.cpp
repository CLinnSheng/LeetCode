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

class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        // Straight forward approach is just using a hash set to track all the nodes
        // Another approach is having 2 pointers 1 fast and 1 slow
        // O(1) Space

        if (head == nullptr)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};
