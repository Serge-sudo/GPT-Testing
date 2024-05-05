#include <iostream>

class Solution {

public:

    ListNode* deleteDuplicates(ListNode* head) {

        if (!head || !head->next) {

            return head;

        }



        ListNode dummy(0);

        ListNode *tail = &dummy;



        while (head) {

            if (head->next && head->val == head->next->val) {

                int duplicate = head->val;

                while (head && head->val == duplicate) {

                    head = head->next;

                }

            } else {

                tail->next = head;

                tail = head;

                head = head->next;

                tail->next = nullptr;

            }

        }



        return dummy.next;

    }

};

