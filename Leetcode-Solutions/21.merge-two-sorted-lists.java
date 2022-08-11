/*
 * @lc app=leetcode id=21 lang=java
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        ListNode helper = new ListNode();
        ListNode dummy = helper;

        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                helper.next = l1;
                l1 = l1.next;
            } else {
                helper.next = l2;
                l2 = l2.next;
            }
            helper = helper.next;
        }

        while (l1 != null) {
            helper.next = l1;
            l1 = l1.next;
            helper = helper.next;
        }

        while (l2 != null) {
            helper.next = l2;
            l2 = l2.next;
            helper = helper.next;
        }

        return dummy.next;
    }
}
// @lc code=end
