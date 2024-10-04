import java.util.Vector;

public class twinSum2130 {
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
        public int pairSum(ListNode head) {
            ListNode p = null, s = head, f = head;
            while (f != null && f.next != null) {
                f = f.next.next;
                ListNode t = s.next;
                s.next = p;
                p = s;
                s = t;
            }
            int max = Integer.MIN_VALUE;
            while (s != null) {
                max = Math.max(max, s.val + p.val);
                s = s.next;
                p = p.next;
            }
            return max;
        }

        // public int pairSum(ListNode head) {
        // Vector<Integer> nums = new Vector<>();
        // for (; head != null; head = head.next) {
        // nums.add(head.val);
        // }
        // int l = 0, r = nums.size() - 1;
        // int max = Integer.MIN_VALUE;
        // while (l != r) {
        // max = Math.max(max, nums.get(l) + nums.get(r));
        // l++;
        // r--;
        // }
        // return max;
        // }
    }
}
