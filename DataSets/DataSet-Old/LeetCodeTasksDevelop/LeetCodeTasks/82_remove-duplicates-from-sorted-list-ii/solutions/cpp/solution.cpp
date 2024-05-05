#include <iostream>


class Solution {

public:

    ListNode* deleteDuplicates(ListNode* head) {

        if (!head || !head->next) {

            return head;

        }



        ListNode dummy(0); // Use a dummy head to simplify edge cases

        ListNode *tail = &dummy; // This will point to the last node of the result list



        while (head) {

            if (head->next && head->val == head->next->val) {

                // Skip all nodes that have the same value

                int duplicate = head->val;

                while (head && head->val == duplicate) {

                    head = head->next;

                }

            } else {

                // Attach the non-duplicate node to the result list

                tail->next = head;

                tail = head;

                head = head->next;

                tail->next = nullptr; // This is important to cut off any existing links

            }

        }



        return dummy.next;

    }

};

