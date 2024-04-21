#include <stdlib.h>


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode dummy;

    dummy.next = head;

    struct ListNode *fast = &dummy, *slow = &dummy;

    

    // Move fast ahead by n+1 positions

    for (int i = 0; i <= n; i++) {

        fast = fast->next;

    }



    // Move both fast and slow until fast reaches the end

    while (fast != NULL) {

        fast = fast->next;

        slow = slow->next;

    }



    // Skip the nth node from the end

    struct ListNode *toDelete = slow->next;

    slow->next = toDelete->next;

    free(toDelete);



    return dummy.next;

}

