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
 
#include <vector>
#include <iostream>
#include <ios>

class Solution 
{
public:
    void reorderList(ListNode* head) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::vector<ListNode*> nodes;
        ListNode *temp = head;
        while (temp)
        {
            nodes.emplace_back(temp);
            temp = temp->next;
        }        

        std::vector<ListNode*> reorder_nodes;
        int left = 0, right = nodes.size() - 1;

        while (left <= right)
        {
            if (left == right)
            {    
                reorder_nodes.emplace_back(nodes[left]);
                break;
            }
            
            reorder_nodes.emplace_back(nodes[left++]);
            reorder_nodes.emplace_back(nodes[right--]);
        }

        head->next = nullptr;
        temp = head;
        for (int i = 1; i < reorder_nodes.size(); i++)
        {
            temp->next = reorder_nodes[i];
            temp = temp->next;
        }

        temp->next = nullptr;
    }
};