/*
 * @lc app=leetcode id=19 lang=java
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {

        ListNode start = new ListNode(0);
        start.next = head;
        ListNode slow = start, fast = start;

        // Move fast in front so that the gap between slow and fast becomes n
        for (int i = 1; i <= n + 1; i++) {
            fast = fast.next;
        }
        // Move fast to the end, maintaining the gap
        while (fast != null) {
            slow = slow.next;
            fast = fast.next;
        }
        // Skip the desired node
        slow.next = slow.next.next;
        return start.next;
    }
}
// @lc code=end
