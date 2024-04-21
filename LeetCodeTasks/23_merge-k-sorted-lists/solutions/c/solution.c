#include <stdlib.h>


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *head = NULL, **tail = &head;

    while (l1 && l2) {

        if (l1->val < l2->val) {

            *tail = l1;

            l1 = l1->next;

        } else {

            *tail = l2;

            l2 = l2->next;

        }

        tail = &(*tail)->next;

    }

    *tail = l1 ? l1 : l2;

    return head;

}



struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    if (listsSize == 0) return NULL;

    int interval = 1;

    while (interval < listsSize) {

        for (int i = 0; i < listsSize - interval; i += 2 * interval) {

            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);

        }

        interval *= 2;

    }

    return lists[0];

}

