class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
    }
}

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return null;
        }

        ListNode dummy = new ListNode(0); // dummy node to handle edge case scenarios
        ListNode prev = dummy; // the last node in the result list
        dummy.next = head;
        
        while (head != null) {
            // Check if current node is a duplicate
            if (head.next != null && head.val == head.next.val) {
                // Skip all nodes equal to head.val
                while (head.next != null && head.val == head.next.val) {
                    head = head.next;
                }
                // Move head one step forward to skip the last duplicate
                head = head.next;
                prev.next = head; // Skip all duplicates
            } else {
                // If not a duplicate, add it to the result list
                prev = prev.next;
                head = head.next;
            }
        }

        // Terminate the list
        prev.next = null;

        return dummy.next;
    }
}
