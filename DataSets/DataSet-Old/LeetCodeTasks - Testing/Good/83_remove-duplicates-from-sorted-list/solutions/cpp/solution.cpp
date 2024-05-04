#include <iostream>


class Solution {

public:

    ListNode* deleteDuplicates(ListNode* head) {

        if (!head) return head;

        ListNode* current = head;

        while (current->next != nullptr) {

            if (current->val == current->next->val) {

                ListNode* temp = current->next;

                current->next = temp->next;

                delete temp;

            } else {

                current = current->next;

            }

        }

        return head;

    }

};

