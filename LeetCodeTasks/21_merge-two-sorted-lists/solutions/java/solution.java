class Solution {

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        // Dummy node acts as the starting point of the new sorted list.

        ListNode dummy = new ListNode(0);

        ListNode tail = dummy;



        // Compare nodes from both lists and attach the smaller one to the merged list

        while (list1 != null && list2 != null) {

            if (list1.val <= list2.val) {

                tail.next = list1;

                list1 = list1.next;

            } else {

                tail.next = list2;

                list2 = list2.next;

            }

            tail = tail.next;

        }



        // Attach any remaining nodes from list1 or list2

        if (list1 != null) {

            tail.next = list1;

        } else if (list2 != null) {

            tail.next = list2;

        }



        return dummy.next; // Return the actual head of the merged list

    }

}

