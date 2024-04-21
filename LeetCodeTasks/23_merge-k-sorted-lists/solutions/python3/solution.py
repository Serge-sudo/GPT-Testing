from typing import List, Optional

import heapq


class Solution:

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

        min_heap = []

        dummy = ListNode(-1)

        current = dummy

        

        for i, l in enumerate(lists):

            if l:

                heapq.heappush(min_heap, (l.val, i, l))

        

        while min_heap:

            val, idx, node = heapq.heappop(min_heap)

            current.next = ListNode(val)

            current = current.next

            node = node.next

            if node:

                heapq.heappush(min_heap, (node.val, idx, node))

        

        return dummy.next

