
class Solution:

    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:

        if left == right:

            return head

        

        # Dummy node to handle edge cases more easily

        dummy = ListNode(0)

        dummy.next = head

        prev = dummy

        

        # Move prev to the node before the section to reverse

        for _ in range(left - 1):

            prev = prev.next

        

        # Start of the section to reverse

        reverse = prev.next

        curr = reverse.next

        

        # Perform the reversal between left and right

        for _ in range(right - left):

            reverse.next = curr.next

            curr.next = prev.next

            prev.next = curr

            curr = reverse.next

            

        return dummy.next

