public class evenOdd328 {
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
        public ListNode oddEvenList(ListNode head) {
            if (head == null || head.next == null || head.next.next == null)
                return head;
            ListNode lastOdd = head;
            ListNode firstEven = head.next;
            ListNode lastEven = head.next;

            while (lastEven != null && lastEven.next != null) {
                lastOdd.next = lastOdd.next.next;
                lastOdd = lastOdd.next;
                lastEven.next = lastEven.next.next;
                lastEven = lastEven.next;
            }
            lastOdd.next = firstEven;
            return head;
        }

        // public ListNode oddEvenList(ListNode head) {
        // if (head == null || head.next == null || head.next.next == null)
        // return head;
        // ListNode lastOdd = head;
        // ListNode firstEven = head.next;
        // ListNode lastEven = head.next;

        // ListNode it = head.next.next;
        // boolean odd = true;
        // while (it != null) {
        // if (odd) {
        // lastOdd.next = it;
        // lastOdd = lastOdd.next;
        // odd = false;
        // } else {
        // lastEven.next = it;
        // lastEven = lastEven.next;
        // odd = true;
        // }
        // it = it.next;
        // }
        // lastOdd.next = firstEven;
        // lastEven.next = null;
        // return head;
        // }
    }
}
