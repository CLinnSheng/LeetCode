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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // So just reverse the LL within the left and right range
        // Find the node before the left boundary because we want to reconnect after reverse the LL within the range
        // And also connect the last node of the LL to the rest of the LL

        // Edge Case
        if (left == right)
        {
            return head;
        }

        int index{1};

        // To handle if left = 1
        ListNode *dummy = new ListNode();
        dummy->next = head;

        // Find the node before the reverse LL
        ListNode *prevLeft = dummy;
        for (int i{}; i < left - 1; i++)
        {
            prevLeft = prevLeft->next;
        }

        // Start reverse the LL within the range
        ListNode *node = prevLeft->next;
        ListNode *prev = nullptr;
        for (int i{}; i < right - left + 1; i++)
        {
            ListNode *next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }

        // Reconnecting the reverse LL
        prevLeft->next->next = node;
        prevLeft->next = prev;

        return dummy->next;
    }
};
