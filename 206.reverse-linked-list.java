/*
 * @lc app=leetcode id=206 lang=java
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode newHead = null;
        while (head != null) {
            // 1. 找到next节点
            ListNode next = head.next;
            // 2. 把当前节点的指针指向上一个节点
            head.next = newHead;
            // 3. 上一个节点往后挪
            newHead = head;
            // 4. 当前节点也往后挪
            head = next;

        }
        return newHead;
    }
}
// @lc code=end
