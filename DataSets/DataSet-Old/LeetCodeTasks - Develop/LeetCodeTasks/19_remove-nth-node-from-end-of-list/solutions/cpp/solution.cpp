#include <iostream>


class Solution {

public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *dummy = new ListNode(0);

        dummy->next = head;

        ListNode *first = dummy;

        ListNode *second = dummy;

        

        // Advance first n+1 steps ahead of second

        for (int i = 0; i <= n; ++i) {

            first = first->next;

        }

        

        // Move first to the end, maintaining the gap

        while (first != nullptr) {

            first = first->next;

            second = second->next;

        }

        

        // Skip the desired node

        ListNode *toDelete = second->next;

        second->next = second->next->next;

        delete toDelete;  // free memory

        

        ListNode *newHead = dummy->next;

        delete dummy;  // free dummy node's memory

        return newHead;

    }

};

