public class remove203 {
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {}

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }
    class Solution {
        public ListNode removeElements(ListNode head, int val) {
            // if (head == null){
            // return null;
            // }
            // ListNode dum = new ListNode();
            // ListNode tail = dum;

            // for (ListNode it = head; it != null; it = it.next){
            // if (it.val == val) {
            // continue;
            // }
            // tail.next = it;
            // tail = tail.next;
            // }
            // tail.next = null;
            // return dum.next;

            return rec(head, val);
        }

        private ListNode rec(ListNode n, int val) {
            if (n == null)
                return null;
            ListNode rest = rec(n.next, val);
            if (n.val == val)
                return rest;
            n.next = rest;
            return n;
        }
    }
}
