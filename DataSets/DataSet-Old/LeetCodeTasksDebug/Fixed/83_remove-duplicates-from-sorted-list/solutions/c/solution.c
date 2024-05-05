#include <stdio.h>

#include <stdlib.h>


struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode *current = head;

    while (current != NULL && current->next != NULL) {

        if (current->val == current->next->val) {

            struct ListNode *temp = current->next;

            current->next = temp->next;

            free(temp);

        } else {

            current = current->next;

        }

    }

    return head;

}



// Helper function to print linked list

void printList(struct ListNode *node) {

    while (node != NULL) {

        printf("%d ", node->val);

        node = node->next;

    }

    printf("\n");

}



// Helper function to create a new node

struct ListNode* newNode(int val) {

    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));

    node->val = val;

    node->next = NULL;

    return node;

}

