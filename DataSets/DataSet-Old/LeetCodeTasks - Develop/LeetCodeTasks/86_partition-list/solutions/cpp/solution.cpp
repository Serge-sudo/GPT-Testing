#include <iostream>


class Solution {

public:

    ListNode* partition(ListNode* head, int x) {

        ListNode lessHead(0), greaterHead(0);  // Dummy nodes to simplify the logic

        ListNode *lessPtr = &lessHead, *greaterPtr = &greaterHead;

        

        while (head != nullptr) {

            if (head->val < x) {

                lessPtr->next = head;

                lessPtr = lessPtr->next;

            } else {

                greaterPtr->next = head;

                greaterPtr = greaterPtr->next;

            }

            head = head->next;

        }

        

        // Connect the two partitions

        lessPtr->next = greaterHead.next;

        greaterPtr->next = nullptr;  // Important to end the list

        

        return lessHead.next;

    }

};

