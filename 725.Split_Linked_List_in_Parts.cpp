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
#include <ios>
#include <iostream>

/*
Goal: Split the linked list into k consecutive linked list parts
Constraint: Length of each part should be as equal as possible & no 2 parts should have a size differing mroe than one.
            Parts should be in the order of occurence in the input list, and parts occuring earlier should always have a size greater than or equal to parts occuring later

Intuition: Find the length of linked list & try to distribute it evenly
The first n % k elements will have an extra element than the others

Time Complexity: O(N) iterate through the link list
Space Complexity: O(N) N new nodes created
*/

class Solution 
{
public:
    std::vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (k == 1) return {head};
        ListNode* temp = head;
        int length_LL = 0;
        while (temp)
        {
            length_LL++;
            temp = temp->next;
        }

        int n_element_1node = length_LL / k;
        int extra_node = length_LL % k;

        std::vector<ListNode*> ans;
        ListNode* prevNode = nullptr;
        ListNode* sub_head = nullptr;

        int cnt = 0;

        while (head || prevNode)
        {
            if (cnt == n_element_1node)
            {
                // Handle special case for 0 element for each node
                if (extra_node)
                {
                    if (prevNode == nullptr)
                    {
                        sub_head = head;
                        prevNode = sub_head;
                    }
                    else
                        prevNode = head;

                    head = head->next;
                    extra_node--;
                }

                prevNode->next = nullptr;
                ans.emplace_back(sub_head);
                sub_head = prevNode = nullptr;
                cnt = 0;
                continue;
            }

            if (sub_head == nullptr) sub_head = head;
            prevNode = head;
            head = head->next;
            cnt++;
        }

        while (ans.size() < k)
            ans.emplace_back(nullptr);

        return ans;
    }
};