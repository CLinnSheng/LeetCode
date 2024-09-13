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

#include <queue>
#include <iostream>
#include <ios>
#include <vector>

/*
Given an array of 'k' linked-lists, each linked-list is sorted in ascending order
Intuition: We need to sort it in a order from a large bunch of data
This will lead to think about a data structure that can store and sort it --> Heap/Priority Queue
First iterate through every LL & push it into a minheap
Then create a new linked list based on the minheap

Time Complexity: O(k*n + k*n lg k*n)
Space Complexity: O(k*n)
*/

struct Comparator
{
    bool operator()(const ListNode* Node1, const ListNode* Node2)
    {
        return Node1->val > Node2->val;
    }
};

class Solution 
{
public:
    
    ListNode* mergeKLists(std::vector<ListNode*>& lists) 
    {
    
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        if (lists.empty()) return nullptr;
        
        std::priority_queue<ListNode*, std::vector<ListNode*>, Comparator> minHeap;
        
        for (auto& head : lists)
        {
            while (head)
            {
                minHeap.emplace(head);
                head = head->next;
            }
        }
        
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        
        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            temp->next = top;
            temp = temp->next;
        }
        
        temp->next = nullptr;
        return ans->next;
    }
};