#include <stdio.h>

#include <stdlib.h>


struct ListNode* swapPairs(struct ListNode* head) {

    if (head == NULL || head->next == NULL) return head;

    

    struct ListNode *current = head;

    struct ListNode *nextNode = head->next;

    

    // Swapping the first two nodes

    current->next = nextNode->next;

    nextNode->next = current;

    head = nextNode;

    

    // Swapping remaining pairs

    while (current->next != NULL && current->next->next != NULL) {

        struct ListNode *temp = current->next->next;

        current->next->next = temp->next;

        temp->next = current->next;

        current->next = temp;

        current = temp->next;

    }

    

    return head;

}

