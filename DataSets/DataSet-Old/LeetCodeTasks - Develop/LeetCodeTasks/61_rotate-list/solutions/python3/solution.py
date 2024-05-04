from typing import Optional

class Solution:

    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        if not head or not head.next or k == 0:

            return head

        

        # First determine the length of the linked list

        length = 1

        current = head

        while current.next:

            current = current.next

            length += 1

        

        # Make the list circular

        current.next = head

        

        # Calculate the effective rotations needed

        k = k % length

        steps_to_new_head = length - k

        

        # Find the new head

        new_tail = head

        for _ in range(steps_to_new_head - 1):

            new_tail = new_tail.next

        new_head = new_tail.next

        

        # Break the circle

        new_tail.next = None

        

        return new_head

