
class Solution:

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:

        # Creating a dummy node which will help in edge cases, such as removing the first element

        dummy = ListNode(0, head)

        first = dummy

        second = dummy



        # Move first to the n+1 th position from the start

        for _ in range(n + 1):

            first = first.next



        # Move first to the end, maintaining the gap

        while first:

            first = first.next

            second = second.next



        # Remove the nth node from the end

        second.next = second.next.next



        # Return the head of the modified list

        return dummy.next

