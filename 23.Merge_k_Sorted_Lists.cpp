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

#include <cmath>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>

/*
Given an array of 'k' linked-lists, each linked-list is sorted in ascending order
Intuition: We need to sort it in a order from a large bunch of data
This will lead to think about a data structure that can store and sort it --> Heap/Priority Queue
First iterate through every LL & push it into a minheap
Then create a new linked list based on the minheap
Time Complexity: O(k*n + k*n lg k*n)
Space Complexity: O(k*n)

Intution For Another: We can actually implement divide and conquer approach
Where we keep merging two LL
This will lead to produce lgK linked list beacuse of keep merigng two LL into 1
and then for every LL we gonna sort n nodes
so the time complexity is O(n * lgK) which is better than using a minheap
Space Complexity: O(1)
*/

// struct Comparator
// {
//     bool operator()(const ListNode* Node1, const ListNode* Node2)
//     {
//         return Node1->val > Node2->val;
//     }
// };

// class Solution
// {
// public:

//     ListNode* mergeKLists(std::vector<ListNode*>& lists)
//     {

//         std::ios_base::sync_with_stdio(false);
//         std::cin.tie(nullptr);
//         std::cout.tie(nullptr);

//         if (lists.empty()) return nullptr;

//         std::priority_queue<ListNode*, std::vector<ListNode*>, Comparator> minHeap;

//         for (auto& head : lists)
//         {
//             while (head)
//             {
//                 minHeap.emplace(head);
//                 head = head->next;
//             }
//         }

//         ListNode* ans = new ListNode();
//         ListNode* temp = ans;

//         while (!minHeap.empty())
//         {
//             auto top = minHeap.top();
//             minHeap.pop();
//             temp->next = top;
//             temp = temp->next;
//         }

//         temp->next = nullptr;
//         return ans->next;
//     }
// };
//

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
class Solution
{
  public:
    ListNode *mergeTwoLL(ListNode *l1, ListNode *l2)
    {
        if (l1 == l2 && l2 == nullptr)
            return nullptr;
        if (l1 == nullptr && l2)
            return l2;
        if (l1 && l2 == nullptr)
            return l1;

        ListNode *merged = new ListNode();
        ListNode *temp = merged;

        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }

            temp = temp->next;
        }

        while (l1)
        {
            temp->next = l1;
            l1 = l1->next;
        }

        while (l2)
        {
            temp->next = l2;
            l2 = l2->next;
        }

        temp->next = nullptr;
        return merged->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int k = lists.size();

        if (k == 0)
            return nullptr;

        // iterate until left only 1 linked list
        while (k > 1)
        {
            for (int i = 0; i < k / 2; i++)
                lists[k] = mergeTwoLL(lists[i], lists[k - i - 1]);

            // in case the initial number of LL is odd because got 1 LL will not merge with any other LL
            k = (k + 1) / 2;
        }

        return lists[0];
    }
};
