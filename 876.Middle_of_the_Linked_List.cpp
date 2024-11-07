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
Goal: return the middle node of the linked list
Constraint: If tehre are 2 middle nodes, return the second middle node

Intuition: We can use 2 pointer, 1 is slow and another 1 is fast which takes 1
more steps. So that every time it move right the half of the fast pointer is the
slow pointer

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
  ListNode *middleNode(ListNode *head) {

    ListNode *fast{head};
    ListNode *slow{head};

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};
