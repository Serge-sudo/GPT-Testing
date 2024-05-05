class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # Dummy node that points to the head of the resulting list
        dummy = ListNode()
        # Pointer to build the non-duplicate list
        current = dummy
        # Pointer to traverse the original list
        while head:
            # Check if it's a start of duplicates sequence
            if head.next and head.val == head.next.val:
                # Skip all duplicates
                while head.next and head.val == head.next.val:
                    head = head.next
                # Move head to the next distinct value
                head = head.next
            else:
                # No duplication, append this node to the result
                current.next = head
                head = head.next
                current = current.next
        # Avoid loose ends in the list to prevent cyclic structures or remnants
        current.next = None
        return dummy.next
