/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 * Approach 1: Brute force instead of merge k lists at once, we can merge two list once at a time
 * Time Complexity of sorting 2 linked list will be O(n)
 * And then we need to sort k linked list will be O(k) --> O(n * k)
 *
 * Approach 2: Will be a little bit similar to this but with a little tweek which is use divide and conquer
 * Time Complexity: O(nlgk)
 */
#include <vector>
class Solution
{
  public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        // int k(lists.size());
        //
        // if (k == 0)
        //     return nullptr;
        //
        // for (int i{1}; i < k; i++)
        //     lists[0] = helper(lists[0], lists[i]);
        //
        // return lists[0];
        return divide(lists, 0, lists.size() - 1);
    }

    ListNode *divide(std::vector<ListNode *> &lists, int left, int right)
    {
        if (left > right)
            return nullptr;

        if (left == right)
            return lists[left];

        int middle = left + (right - left) / 2;
        ListNode *leftLL = divide(lists, left, middle);
        ListNode *rightLL = divide(lists, middle + 1, right);

        return conquer(leftLL, rightLL);
    }

    ListNode *conquer(ListNode *list1, ListNode *list2)
    {
        ListNode *merged = new ListNode();
        ListNode *temp = merged;

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

        // In case one of it havent end yet
        // But only have one linked list that will face tihs issues so can straight away prune instead of keep looping
        if (list1)
        {
            temp->next = list1;
        }
        if (list2)
        {
            temp->next = list2;
        }
        return merged->next;
    }
};
