
class Solution {

    public ListNode deleteDuplicates(ListNode head) {

        if (head == null) {

            return null;

        }

        

        ListNode dummy = new ListNode(0); // dummy node to handle edge case scenarios

        ListNode prev = dummy; // the last node in the result list

        

        while (head != null) {

            // Check if current node is a duplicate

            if (head.next != null && head.val == head.next.val) {

                // Skip all nodes equal to head.val

                while (head.next != null && head.val != head.next.val) {

                    head = head.next;

                }

                // Move head one step forward to skip the last duplicate

                head = head.next;

            } else {

                // If not a duplicate, add it to the result list

                prev.next = head;

                head = head.next;

                prev = head;


            }

        }

        

        // Terminate the list

        prev.next = null;

        return dummy.next;

    }

}

