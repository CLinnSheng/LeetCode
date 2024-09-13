#include <iostream>
#include <ios>

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
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list.
Constraint: If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Intuition:
The number of reverse will be the length of LL / k
So what we can do is iterate through LL & for every k we reverse it
to check whether is it valid or not we have a helper function that return the last node for k nodes
If is a null then we not gonna reverse it
Solving it group by group and have track of the node before the group and after the group easy for connecting back to the LL
Time Complexity: O(n*k)
Space Complexity: O(n)

*/

class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        // Lets clear the base case 
        if (head == nullptr || k == 1) return head;
        
        ListNode* ans = new ListNode(0, head);
        ListNode* groupPrev = ans;

        while (true)
        {
            auto kth_node = gettingLastNodeforKth(groupPrev, k);

            if (kth_node == nullptr) break;
            
            // Set of LL after the kth node
            ListNode* groupNext = kth_node->next;

            // Reversing the LL
            ListNode* curr = groupPrev->next;
            ListNode* prev = groupNext;

            while (curr != groupNext)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Before reversing it was the first node in the kth group
            ListNode* temp = groupPrev->next;
            // while kth_node initially was the last node but now become the first node
            groupPrev->next = kth_node;
            // Now update the groupPrev to the node before the next group
            groupPrev = temp;
        }

        return ans->next;
    }

    ListNode* gettingLastNodeforKth(ListNode* curr, int k)
    {
        while (curr && k > 0)
        {
            curr = curr->next;
            k--;
        }

        return curr;
    }
};