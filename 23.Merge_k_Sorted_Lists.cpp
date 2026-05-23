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
 * Each LL is sorted. How can we merge all of it together into 1?
 * Merging n (where n > 2) is hard but we know that merging 2 linked list is easy
 * So we can actually just keep merging 2 linked list
 * Time Complexity: O(m*n)
 * - m -> Length of lists
 * - n -> Longest linked list
 * Space Complexity: O(1)
 * If notice from this approach, one of the linkedlist is actually keep growing larger and larger
 *
 * What if we can consecutively merging 2 smaller linked list or in this way
 * a b c d --> a & b + c & d
 * and then merged the 2 merged linked list
 *
 * This lead us to divide and conquer
 * Just 2 operation
 * 1. Divide
 *  - Keep dividing it until only left 1 then slowly build up
 * 2. Conquer
 *  - Merging 2 sides together
 * */

#include <vector>
class Solution
{
  private:
    ListNode *conquer(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode();
        ListNode *temp = head;

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

        // Append the longer LL which never traversed finish
        if (list1)
        {
            temp->next = list1;
        }
        if (list2)
        {
            temp->next = list2;
        }

        return head->next;
    }

    ListNode *divide(const std::vector<ListNode *> &lists, int left, int right)
    {
        // Base Case
        // Check whether the pointer crossed
        if (left > right)
        {
            return nullptr;
        }
        // Divide until only left 1 element
        if (left == right)
        {
            return lists[left];
        }

        // Keep dividing it
        int middle = left + (right - left) / 2;
        ListNode *leftSide = divide(lists, left, middle);
        ListNode *rightSide = divide(lists, middle + 1, right);

        return conquer(leftSide, rightSide);
    }

  public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        // Approach 1
        // int n = lists.size();
        //
        // // Base Case
        // if (n == 0)
        // {
        //     return nullptr;
        // }
        //
        // for (int i{1}; i < n; i++)
        // {
        //     lists[0] = mergeLinkedList(lists[0], lists[i]);
        // }
        //
        // return lists[0];

        // Approach 2
        return divide(lists, 0, lists.size() - 1);
    }
};
