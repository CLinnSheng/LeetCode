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
#include <ios>
#include <iostream>
/*
Goal: Reverse the list
Intuition: Have 2 pointer, 1 pointer keep tracking the previous node and another pointer keep updating to the latest
node Time Complexity: O(N)
*/

class Solution
{
  public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }

        // Having another pointer tracking the last ptr
        ListNode *prev{};

        while (head)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};
