/*
 * @lc app=leetcode id=230 lang=java
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (69.17%)
 * Likes:    8459
 * Dislikes: 148
 * Total Accepted:    947.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given the root of a binary search tree, and an integer k, return the k^th
 * smallest value (1-indexed) of all the values of the nodes in the tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is n.
 * 1 <= k <= n <= 10^4
 * 0 <= Node.val <= 10^4
 * 
 * 
 * 
 * Follow up: If the BST is modified often (i.e., we can do insert and delete
 * operations) and you need to find the kth smallest frequently, how would you
 * optimize?
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    private int smallerCount(int num, TreeNode root) {
        if (root == null)
            return 0;
        int count = 0;
        if (root.val <= num) {
            count += 1;
            count += smallerCount(num, root.left);
            count += smallerCount(num, root.right);
        } else {
            count += smallerCount(num, root.left);
        }
        return count;
    }

    public int kthSmallest(TreeNode root, int k) {
        int l = 0;
        int r = 10010;
        while (l < r) {
            int mid = l + r >> 1;
            if (smallerCount(mid, root) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
}
// @lc code=end
