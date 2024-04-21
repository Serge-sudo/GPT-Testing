#include <stddef.h>


struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    if (head == NULL || k == 1) return head;

    

    struct ListNode dummy;

    dummy.next = head;

    struct ListNode *prevGroupEnd = &dummy;

    

    while (1) {

        struct ListNode *kth = prevGroupEnd;

        for (int i = 0; i < k && kth != NULL; i++) {

            kth = kth->next;

        }

        

        if (kth == NULL) break;  // Less than k nodes remain; stop here

        

        struct ListNode *groupStart = prevGroupEnd->next;

        struct ListNode *prev = kth->next;

        struct ListNode *curr = groupStart;

        

        while (curr != prev) {

            struct ListNode *next = curr->next;

            curr->next = prev;

            prev = curr;

            curr = next;

        }

        

        prevGroupEnd->next = kth;

        prevGroupEnd = groupStart;

    }

    

    return dummy.next;

}

