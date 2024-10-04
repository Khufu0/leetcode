/**
 * middleNode2095
 */
public class middleNode2095 {
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    class Solution {
        public ListNode deleteMiddle(ListNode head) {
            if (head.next == null)
                return null;
            ListNode slower = null;
            ListNode slow = head;
            ListNode fast = head;
            while (fast != null && fast.next != null) {
                slower = slow;
                slow = slow.next;
                fast = fast.next.next;
            }
            slower.next = slower.next.next;
            return head;
        }
    }
}