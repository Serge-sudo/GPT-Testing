#include <stdio.h>

#include <stdlib.h>


struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {

    if (left == right) return head;



    struct ListNode dummy;

    dummy.next = head;

    struct ListNode* prev = &dummy;



    // Advance to the node just before the 'left' position

    for (int i = 1; i < left; i++) {

        prev = prev->next;

    }



    // Reverse from 'left' to 'right'

    struct ListNode* curr = prev->next;

    struct ListNode* next = NULL;

    struct ListNode* lastUnreversed = curr;

    struct ListNode* reversedTail = prev->next;

    

    for (int i = left; i <= right; i++) {

        next = curr->next;

        curr->next = prev->next;

        prev->next = curr;

        curr = next;

    }



    // Connect the last part

    lastUnreversed->next = curr;



    return dummy.next;

}

