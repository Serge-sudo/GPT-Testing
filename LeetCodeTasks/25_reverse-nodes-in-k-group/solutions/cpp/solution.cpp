#include <vector>

#include <algorithm>


class Solution {

public:

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1) return head;



        ListNode dummy(0);

        dummy.next = head;

        ListNode *prev = &dummy, *curr = head, *nex = nullptr;



        int len = 0;

        while (curr) { // Calculate length of list

            len++;

            curr = curr->next;

        }



        while (len >= k) {

            curr = prev->next;

            nex = curr->next;

            for (int i = 1; i < k; ++i) {

                curr->next = nex->next;

                nex->next = prev->next;

                prev->next = nex;

                nex = curr->next;

            }

            prev = curr;

            len -= k;

        }



        return dummy.next;

    }

};

