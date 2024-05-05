#include <stdlib.h>

struct ListNode* partition(struct ListNode* head, int x) {

    struct ListNode *lessHead = NULL, *lessTail = NULL;

    struct ListNode *greaterHead = NULL, *greaterTail = NULL;

    struct ListNode *current = head;



    while (current) {

        if (current->val < x) {

            if (!lessHead) {

                lessHead = lessTail = current;

            } else {

                lessTail->next = current;

                lessTail = current;

            }

        } else {

            if (!greaterHead) {

                greaterHead = greaterTail = current;

            } else {

                greaterTail->next = current;

                greaterTail = current;

            }

        }

        current = current->next;

    }



    if (lessTail) {

        lessTail->next = greaterHead;

    }



    if (greaterTail) {

        greaterTail->next = NULL;

    }



    return lessHead ? lessHead : greaterHead;

}

