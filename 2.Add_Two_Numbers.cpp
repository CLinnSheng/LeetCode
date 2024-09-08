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
Goal: Return the linked list of sum of every single node from each linked list
Constraint: The digits are stored in reverse order
eg: 
2->4->3 --> 342
5->6->4 --> 465
342 + 465 = 801
return 1->0->8

Intuition: Since the first node in each linked list is the last digit
so we just simply sum up and need to take care of the carry

Time Complexity: O(N)
Space Complexity: O(N)
*/
#include <iostream>
#include <ios>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        ListNode* tempLL = new ListNode();
        ListNode* ansLL = tempLL;

        int carry = 0;

        while (l1 || l2 || carry)
        {
            // need to take care of l1 & l2 when it is point to nullptr
            int n1 = l1? l1->val : 0;
            int n2 = l2? l2->val : 0;

            int sum = n1 + n2 + carry;
            int last_digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(last_digit);
            tempLL->next = newNode;
            tempLL = tempLL->next;

            // take care when l1 & l2 is nullptr
            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr; 
        }

        return ansLL->next;
    }
};
