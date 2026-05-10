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
/*
Goal: Merge the two list
Intuition: Have 2 pointer 1 on each list. Update the pointer by comparing
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <ios>
#include <iostream>
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Sort 2 sorted LL
        // Having 1 pointer on each LL

        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }

        ListNode *head = new ListNode();
        ListNode *temp = head;

        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                temp->next = list2;
                list2 = list2->next;
            }
            else
            {
                temp->next = list1;
                list1 = list1->next;
            }

            temp = temp->next;
        }

        // Append the LL havent traverse finish
        if (list1)
        {
            temp->next = list1;
        }
        if (list2)
        {
            temp->next = list2;
        }

        return head->next;
    }
};
