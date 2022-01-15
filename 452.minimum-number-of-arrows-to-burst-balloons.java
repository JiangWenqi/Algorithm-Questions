import java.util.Arrays;

/*
 * @lc app=leetcode id=452 lang=java
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        int[] prev = points[0];
        int arrows = 1;
        for (int i = 1; i < points.length; i++) {
            int[] curr = points[i];
            if (prev[1] < curr[0]) {
                arrows++;
                prev = curr;
            } else {
                prev[0] = Math.max(prev[0], curr[0]);
                prev[1] = Math.min(prev[1], curr[1]);
            }
        }
        return arrows;
    }
}
// @lc code=end
