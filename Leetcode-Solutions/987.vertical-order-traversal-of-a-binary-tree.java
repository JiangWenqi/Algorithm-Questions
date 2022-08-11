import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.TreeMap;

/*
 * @lc app=leetcode id=987 lang=java
 *
 * [987] Vertical Order Traversal of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Point implements Comparable<Point> {
    TreeNode node;
    int x, y;

    Point(TreeNode node, int x, int y) {
        this.node = node;
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Point otherPoint) {
        if (this.y == otherPoint.y) {
            return this.node.val - otherPoint.node.val;
        }
        return this.y - otherPoint.y;
    }
}

class Solution {

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        // 结果存储
        List<List<Integer>> result = new LinkedList<>();
        // TreeMap
        TreeMap<Integer, LinkedList<Integer>> resultMap = new TreeMap<>();
        // Priority 队列，用来做层次遍历 需要实现排序方法
        PriorityQueue<Point> queue = new PriorityQueue<>();

        queue.offer(new Point(root, 0, 0));
        while (!queue.isEmpty()) {
            Point point = queue.poll();
            // 如果这一列目前还没存储链表，那就新建一个
            if (!resultMap.containsKey(point.x)) {
                resultMap.put(point.x, new LinkedList<>());
            }
            // 把值填进去
            resultMap.get(point.x).add(point.node.val);
            // left child
            if (point.node.left != null) {
                Point left = new Point(point.node.left, point.x - 1, point.y + 1);
                queue.offer(left);
            }
            // right child
            if (point.node.right != null) {
                Point right = new Point(point.node.right, point.x + 1, point.y + 1);
                queue.offer(right);
            }
        }

        for (LinkedList<Integer> list : resultMap.values()) {
            result.add(list);
        }

        return result;
    }

}
// @lc code=end

