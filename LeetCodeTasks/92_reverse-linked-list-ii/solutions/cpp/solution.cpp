#include <iostream>


class Solution {

public:

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right) return head;



        ListNode dummy(0);

        dummy.next = head;

        ListNode* prev = &dummy;



        // Move prev to the node immediately before the left position

        for (int i = 0; i < left - 1; ++i) {

            prev = prev->next;

        }



        // Start reversing from this node

        ListNode* reverseStart = prev->next;

        ListNode* curr = reverseStart->next;



        // Reverse the sublist from left to right

        for (int i = 0; i < right - left; ++i) {

            reverseStart->next = curr->next;

            curr->next = prev->next;

            prev->next = curr;

            curr = reverseStart->next;

        }



        return dummy.next;

    }

};

