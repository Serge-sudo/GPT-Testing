from typing import Optional

class Solution:

    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:

        # Dummy heads of the 1st and 2nd partitions

        small_dummy = ListNode(0)

        large_dummy = ListNode(0)

        

        # Current tails of the 1st and 2nd partitions

        small = small_dummy

        large = large_dummy

        

        # Iterate over the original list and assign each node to the correct partition

        while head:

            if head.val < x:

                small.next = head

                small = small.next

            else:

                large.next = head


            head = head.next

        

        # Clean up the end of the second partition

        large.next = None

        

        # Connect the two partitions

        small.next = large_dummy.next

        

        return small_dummy.next

