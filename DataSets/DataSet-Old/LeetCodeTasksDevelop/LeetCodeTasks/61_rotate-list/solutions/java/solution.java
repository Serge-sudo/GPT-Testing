/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }
        
        // Find the length of the linked list
        ListNode current = head;
        int length = 1;
        while (current.next != null) {
            current = current.next;
            length++;
        }
        
        // Connect the tail to the head to make it a circular list
        current.next = head;
        
        // Find the number of effective rotations
        k = k % length;
        int stepsToNewHead = length - k;
        ListNode newTail = current;
        
        // Find the new tail after stepsToNewHead
        for (int i = 0; i < stepsToNewHead; i++) {
            newTail = newTail.next;
        }
        
        // Set the new head and break the loop
        ListNode newHead = newTail.next;
        newTail.next = null;
        
        return newHead;
    }
}
