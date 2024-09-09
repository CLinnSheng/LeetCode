/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <ios>
#include <unordered_set>

/*
Goal: Check whether there is a cycle in the linked list
Intuition: Use a set to store the node and check whether is it already visited
If we reach a nullptr means there is no cycle
Time Complexity: O(n) Length of LL
Space Complexity: O(n) Length of LL

Another way is having 2 pointer
1 pointer is moving 1 move ahead of another pointer
The time complexity is also the same O(n) but slightly better
*/

class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        // std::unordered_set<ListNode*> set_Node;

        // while (head)
        // {
        //     if (head == nullptr) return false;

        //     if (set_Node.count(head) == 0) set_Node.insert(head);
        //     else return true;

        //     head = head->next;
        // }

        // return false;

        ListNode* first = head;
        ListNode* second = head;

        while (second && second->next)
        {
            second = second->next->next;
            first = first->next;

            if (first == second) return true;
        }

        return false;
    }
};