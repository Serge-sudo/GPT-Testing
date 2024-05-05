#include <vector>

#include <queue>


class Solution {

public:

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {

        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };

        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> min_heap(compare);

        

        for (ListNode* list : lists) {

            if (list) {

                min_heap.push(list);

            }

        }

        

        ListNode dummy;

        ListNode* tail = &dummy;

        

        while (!min_heap.empty()) {

            ListNode* top = min_heap.top();

            min_heap.pop();

            tail->next = top;

            tail = tail->next;

            

            if (top->next) {

                min_heap.push(top->next);

            }

        }

        

        return dummy.next;

    }

};

