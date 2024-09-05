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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        ListNode *temp = new ListNode();
        ListNode *head = temp;
        
        if (list1 == list2 && list2 == nullptr) return nullptr;
        
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
        
        if (list1) temp->next = list1;
        else temp->next = list2;
        
        return head->next;
    }
};