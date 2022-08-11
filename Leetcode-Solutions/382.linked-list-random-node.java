import java.util.Random;

/*
 * @lc app=leetcode id=382 lang=java
 *
 * [382] Linked List Random Node
 */

// @lc code=start
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

    ListNode dummy = new ListNode(-1);
    int count = 0;
    public Solution(ListNode head) {
        dummy.next = head;
        while (head != null) {
            count ++;
            head = head.next;
        }
    }
    
    public int getRandom() {
        Random r = new Random();
        int order = r.nextInt(count);
        ListNode head = dummy.next;
        for (int i = 0; i < order; i++) {
            head = head.next;
        }
        return head.val;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
// @lc code=end

