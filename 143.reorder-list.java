import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode id=143 lang=java
 *
 * [143] Reorder List
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
    public void reorderList(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode left = head, right = reverse(slow);
        ListNode prev = new ListNode(-1);
        while (left != null && right != null) {
            prev.next = left;
            left = left.next;
            prev.next.next = right;
            right = right.next;
            prev = prev.next.next;
        }
        prev.next = null;

        Queue<Integer> q = new LinkedList<>();


    }

    private ListNode reverse(ListNode head) {
        ListNode prev = null, curr = head, next;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}
// @lc code=end
