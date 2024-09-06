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

#include <iostream>
#include <unordered_set>
#include <vector>
/*
Goal: Return the head of the modified linked list by removing all nodes from the linkedlist that have a value exists in the nums array

Intuition: Use set data structure to store the array of nums so we have dont to iterate through the whole array everytime checking
Have a pointer point to the prev node, so that we can always keep track of the prev node
Time Complexity: O(N) -> Iterate through the nums & head (Time complexity for inserting element into the set is also O(n))
Space Complexity: O(N) -> Storing the nums
*/
class Solution 
{
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) 
    {
        std::ios_base :: sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int n = nums.size();
        
        // nothing to remove
        if (n == 0) return head; 
        
        // Set to store the nums
        std::unordered_set<int> remove_numbers(nums.begin(), nums.end());
        
        ListNode *curr = head;
        ListNode *prev = nullptr;
        
        while (curr)
        {            
            // need to handle special case for the head
            if (remove_numbers.count(curr->val))
            {    
                if (curr == head)
                {
                    head = head->next;
                    curr = head;
                }    
                else
                {
                    prev->next = curr->next;
                    ListNode *delete_node = curr;
                    curr = curr->next;
                    delete delete_node;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;  
            }
        }
        
        return head;
    }
};