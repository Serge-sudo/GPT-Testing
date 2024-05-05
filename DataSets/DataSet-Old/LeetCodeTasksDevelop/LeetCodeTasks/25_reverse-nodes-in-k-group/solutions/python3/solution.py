
class Solution:

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:

        if head is None or k == 1:

            return head

        

        # Dummy node to handle edge cases easily

        dummy = ListNode(-1)

        dummy.next = head

        prev_end = dummy

        current = head

        

        # Helper function to reverse k nodes

        def reverse(start, k):

            prev, node = None, start

            for _ in range(k):

                next_node = node.next

                node.next = prev

                prev = node

                node = next_node

            return prev, start  # New head and tail after reversal

        

        # Count nodes

        count = 0

        while current:

            count += 1

            if count % k == 0:

                next_group = current.next

                # Reverse the k nodes

                new_head, new_tail = reverse(prev_end.next, k)

                prev_end.next = new_head

                new_tail.next = next_group

                prev_end = new_tail

                current = next_group

            else:

                current = current.next



        return dummy.next

