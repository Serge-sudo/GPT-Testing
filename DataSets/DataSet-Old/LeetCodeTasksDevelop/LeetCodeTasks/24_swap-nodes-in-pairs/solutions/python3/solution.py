from typing import Optional



class Solution:

    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:

        dummy = ListNode(0)

        dummy.next = head

        prev = dummy

        

        while head and head.next:

            first = head

            second = head.next

            

            # Swapping

            prev.next = second

            first.next = second.next

            second.next = first

            

            # Reinitializing the pointers for next swap

            prev = first

            head = first.next

            

        return dummy.next

