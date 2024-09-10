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
Goal: Insert a new node vwith a value equal to the greatest common divisor between the 2 values from both side

Intuition: Having 2 pointer, 1 pointer moving 1 move ahead of the other pointer
Handle special case when there is only 1 node, 0 node and also the faster pointer point to the last node
Time Complexity: O(N) --> As we just iterate through the linked list
Space Complexity: O(1) --> Dont really use up any space
*/
#include <iostream>
#include <ios>

class Solution 
{
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        
        ListNode* first = head->next;
        ListNode* second = head;
        
        while (first && first->next)
        {
            int gcd = find_GCD(first->val, second->val);
            ListNode* new_node = new ListNode(gcd);
            
            second->next = new_node;
            new_node->next = first;
            
            first = first->next;
            second = second->next->next;
        }
        
        if (first && second)
        {
            int gcd = find_GCD(first->val, second->val);
            ListNode* new_node = new ListNode(gcd);
            
            second->next = new_node;
            new_node->next = first;        
        }
        
        return head;
    }
    
    int find_GCD(int val1, int val2)
    {
        if (val1 == 0) return val2;
        if (val2 == 0) return val1;
        
        return val1 > val2 ? find_GCD(val1 - val2, val2) : find_GCD(val1, val2 - val1);
    }
};
