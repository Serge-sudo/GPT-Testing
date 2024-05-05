#include <stddef.h>


struct ListNode* rotateRight(struct ListNode* head, int k) {

    if (head == NULL || head->next == NULL || k == 0) return head;



    // Compute the length of the list

    struct ListNode *current = head;

    int length = 1;

    while (current->next != NULL) {

        current = current->next;

        length++;

    }



    // Make the list circular

    current->next = head;



    // Calculate effective rotations needed

    k = k % length;

    int stepsToNewHead = length - k;

    

    // Find the new end of the rotated list

    struct ListNode *newTail = head;

    for (int i = 0; i < stepsToNewHead - 1; i++) {

        newTail = newTail->next;

    }



    // Set the new head

    struct ListNode *newHead = newTail->next;



    // Break the loop

    newTail->next = NULL;



    return newHead;

}

