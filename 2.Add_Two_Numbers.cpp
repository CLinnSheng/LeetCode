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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Adding 2 numbers from 2 LL
        // Just simply add it and create a new node
        // The only thing we need to handle is carry
        int carry{};
        ListNode *head = new ListNode();
        ListNode *temp = head;

        while (l1 || l2 || carry)
        {
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;

            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }

            int sum = l1_val + l2_val + carry;
            carry = sum / 10;

            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return head->next;
    }
};
