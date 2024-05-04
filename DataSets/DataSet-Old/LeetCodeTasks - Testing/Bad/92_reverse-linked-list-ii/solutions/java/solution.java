class Solution {

    public ListNode reverseBetween(ListNode head, int left, int right) {

        if (head == null || left == right) return head;

        

        ListNode dummy = new ListNode(0);  // Dummy node to handle edge cases

        dummy.next = head;

        ListNode prev = dummy;

        

        // Move prev to the node immediately before the start of the reversal section

        for (int i = 0; i < left - 1; i++) {

            prev = prev.next;

        }

        

        // Start reversing the list

        ListNode current = prev.next;

        ListNode next;

        ListNode tail = current;  // The first node that will end up being the end of reversed section

        

        for (int i = left; i < right; i++) {

            next = current.next;

            current.next = prev.next;

            current = next;

        }

        

        // Connect the reversed section back to the rest of the list

        tail.next = current;

        

        return dummy.next;

    }

}

