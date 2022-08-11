/*
 * @lc app=leetcode id=222 lang=java
 *
 * [222] Count Complete Tree Nodes
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
    public int countNodes(TreeNode root) {

        int ans = 0;
        if (root == null) {
            return ans;
        }

        int left = countLeft(root.left);
        int right = countRight(root.right);
        if (left == right) {
            return (1 << left) - 1;
        } else {
            return 1 + countNodes(root.left) + countNodes(root.right);
        }

    }

    private int countLeft(TreeNode node) {
        int count = 1;
        while (node != null) {
            count++;
            node = node.left;
        }
        return count;
    }

    private int countRight(TreeNode node) {
        int count = 1;
        while (node != null) {
            count++;
            node = node.right;
        }
        return count;
    }


}
// @lc code=end
