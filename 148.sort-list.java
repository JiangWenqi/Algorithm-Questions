/*
 * @lc app=leetcode id=148 lang=java
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode[] halfSplits = split(head);
        ListNode l = sortList(halfSplits[0]);
        ListNode r = sortList(halfSplits[1]);
        return merge(l, r);
    }

    private ListNode[] split(ListNode head) {
        ListNode prev = null, slow = head, fast = head;
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode mid = slow;
        prev.next = null;
        return new ListNode[] { head, mid };
    }

    private ListNode merge(ListNode l, ListNode r) {
        ListNode dummy = new ListNode();
        ListNode head = dummy;
        while (l != null && r != null) {
            if (l.val < r.val) {
                head.next = l;
                l = l.next;
            } else {
                head.next = r;
                r = r.next;
            }
            head = head.next;
        }
        if (l != null) {
            head.next = l;
        }
        if (r != null) {
            head.next = r;
        }
        return dummy.next;
    }
}
// @lc code=end
