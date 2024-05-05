class Solution {

    public ListNode swapPairs(ListNode head) {

        // Create a dummy node which acts as the starting point of the list

        ListNode dummy = new ListNode(0);

        dummy.next = head;

        ListNode current = dummy;



        // Loop through the list in pairs

        while (current.next != null && current.next.next != null) {

            ListNode first = current.next; // First node in the pair

            ListNode second = current.next.next; // Second node in the pair



            // Swapping logic

            first.next = second.next;

            second.next = first;

            current.next = second;



            // Move the current pointer two nodes ahead

            current = first;

        }



        // Return the new head of the list

        return dummy.next;

    }

}

