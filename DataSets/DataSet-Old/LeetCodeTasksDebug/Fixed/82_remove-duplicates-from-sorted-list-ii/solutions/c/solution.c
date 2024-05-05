#include <stdlib.h>


struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode dummy;

    dummy.next = head;

    struct ListNode *prev = &dummy;



    while (head != NULL) {

        // Check if it's a start of duplicates

        if (head->next != NULL && head->val == head->next->val) {

            // Skip all duplicates

            while (head->next != NULL && head->val == head->next->val) {

                head = head->next;

            }

            // Connect prev to the node after the last duplicate

            head->next = prev->next;

        } else {

            // Move prev if no duplicate in this section

            prev = prev->next;

        }

        head = head->next;

    }

    return dummy.next;

}

