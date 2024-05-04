import java.util.PriorityQueue;


class Solution {

    public ListNode mergeKLists(ListNode[] lists) {

        if (lists == null || lists.length == 0) return null;

        

        PriorityQueue<ListNode> heap = new PriorityQueue<>((a, b) -> a.val - b.val);

        

        // Initialize the heap with the first node of each list if it is not empty

        for (ListNode node : lists) {

            if (node != null) {

                heap.add(node);

            }

        }

        

        ListNode dummy = new ListNode(0);

        ListNode current = dummy;

        

        while (!heap.isEmpty()) {

            ListNode minNode = heap.poll();

            current.next = minNode;

            current = current.next;

            if (minNode.next != null) {

                heap.add(minNode.next);

            }

        }

        

        return dummy.next;

    }

}

