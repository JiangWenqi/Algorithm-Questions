import java.util.Stack;

import javax.swing.tree.TreeNode;

import com.sun.source.tree.Tree;

/*
 * @lc app=leetcode id=235 lang=java
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // Approach 1
        /*
         * int m = p.val;
         * int n = q.val;
         * while (true) {
         * if (root.val > m && root.val > n) {
         * root = root.left;
         * } else if (root.val < m && root.val < n) {
         * root = root.right;
         * } else {
         * break;
         * }
         * }
         * return root;
         * 
         */

        if (root.val > p.val && root.val > q.val)
            return lowestCommonAncestor(root.left, p, q);
        else if (root.val < p.val && root.val < q.val)
            return lowestCommonAncestor(root.right, p, q);
        else
            return root;

    }
}
// @lc code=end
