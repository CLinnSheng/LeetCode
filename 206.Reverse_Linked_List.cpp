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
Intuition: Have 2 pointer, 1 pointer keep tracking the previous node and another pointer keep updating to the latest node
Time Complexity: O(N)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head)   
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        if (head == nullptr) return nullptr;
        
        ListNode* prev_node = nullptr;
        
        while (head)
        {
            ListNode* temp = head->next;
            head->next = prev_node;
            prev_node = head;
            head = temp;
        }
        
        return prev_node;
    }
};