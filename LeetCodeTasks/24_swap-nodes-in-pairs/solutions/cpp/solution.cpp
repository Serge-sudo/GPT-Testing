#include <iostream>


class Solution {

public:

    ListNode* swapPairs(ListNode* head) {

        if (head == nullptr || head->next == nullptr) return head;

        

        ListNode *dummy = new ListNode(0);

        dummy->next = head;

        ListNode *current = dummy;

        

        while (current->next != nullptr && current->next->next != nullptr) {

            ListNode *first = current->next;

            ListNode *second = first->next;

            

            first->next = second->next;

            second->next = first;

            current->next = second;

            

            current = first;

        }

        

        ListNode *newHead = dummy->next;

        delete dummy;

        return newHead;

    }

};

