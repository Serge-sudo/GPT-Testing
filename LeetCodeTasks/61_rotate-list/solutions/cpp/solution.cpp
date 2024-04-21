#include <iostream>


class Solution {

public:

    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0) return head;



        // First, let's determine the length of the list

        int length = 1; // we start with one because we are already at the head

        ListNode* tail = head;

        while (tail->next) {

            tail = tail->next;

            length++;

        }



        // Connect the tail to head to make it a circular list

        tail->next = head;



        // Find the new tail, which is (length - k % length - 1)th node

        k = k % length; // This handles cases where k >= length

        int stepsToNewTail = length - k - 1;

        ListNode* newTail = head;

        for (int i = 0; i < stepsToNewTail; i++) {

            newTail = newTail->next;

        }



        // The new head is the next node after the new tail

        ListNode* newHead = newTail->next;



        // Break the cycle

        newTail->next = nullptr;



        return newHead;

    }

};

